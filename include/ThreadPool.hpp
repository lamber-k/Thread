//
// ThreadPool.hh for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/plazza
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Tue Apr 16 10:32:04 2013 lambert kevin
// Last update Mon Oct  7 15:27:06 2013 lambert kevin
//

#ifndef THREADPOOL_HH_
# define THREADPOOL_HH_

# include	<vector>
# include	<list>
# include	"Threads.hpp"
# include	"ThreadWork.hpp"
# include	"ThreadCond.hh"
# include	"ThreadMutex.hh"

namespace	Thread
{
  class		PoolQueue
  {
  protected:
    bool		doNotBlockWhenFull;
    bool		queueClose;
    bool		queueShutdown;
    Mutex		queueLock;
    Cond		queueNotEmpty;
    Cond		queueNotFull;
    Cond		queueEmpty;
    unsigned int	maxQueueSize;

  public:
    PoolQueue(unsigned int maxQueueSize, bool doNotBlockWhenFull) :
      doNotBlockWhenFull(doNotBlockWhenFull), queueClose(false),
      queueShutdown(false), maxQueueSize(maxQueueSize)
    {
    }
    ~PoolQueue() {}
  };

  template <typename T, typename U>
  class		Pool : protected PoolQueue
  {
    std::vector<Threads<Pool<T, U> *, void (*)(Pool<T, U> *)> *>	Th;
    std::list<Work<T, U> >	listWork;
    unsigned int		numThread;

  public:
    Pool(unsigned int numTh, unsigned int maxQueueSize, bool doNotBlockWhenFull = true) :
      PoolQueue(maxQueueSize, doNotBlockWhenFull), numThread(numTh)
    {
      for (unsigned int i = 0; i < numThread; i++)
      	Th.insert(Th.begin(), new Threads<Pool<T, U> *, void (*)(Pool<T, U> *)>(&routine, this));
    }

    virtual ~Pool()
    {
      for (unsigned int i = 0; i < numThread; i++)
      	delete Th[i];
    }

    bool		run()
    {
      for (unsigned int i = 0; i < numThread; i++)
	{
	  if (!Th[i]->run())
	    {
	      stop(false);
	      return (false);
	    }
	}
      return (true);
    }

    bool		stop(bool finish)
    {
      this->queueLock.lock();
      if (queueClose || queueShutdown)
	{
	  this->queueLock.unlock();
	  return (true);
	}
      queueClose = true;
      if (finish)
	while (listWork.size() != 0)
	  queueEmpty.wait(queueLock);
      queueShutdown = true;
      this->queueLock.unlock();
      queueNotEmpty.broadcast();
      queueNotFull.broadcast();
      for (unsigned int i = 0; i < numThread; i++)
	Th[i]->join();
      return (true);
    }

    bool		addWork(Work<T, U> work)
    {
      this->queueLock.lock();
      if (queueShutdown || queueClose)
	{
	  this->queueLock.unlock();
	  return (false);
	}
      if (doNotBlockWhenFull && listWork.size() == maxQueueSize)
	{
	  this->queueLock.unlock();
	  return (false);
	}
      if (listWork.size() == maxQueueSize &&
	  !(queueShutdown || queueClose))
	{
	  queueNotFull.wait(queueLock);
	}
      if (listWork.size() == 0)
	queueNotEmpty.broadcast();
      listWork.push_back(work);
      this->queueLock.unlock();
      return (true);
    }

  protected:
    static void		routine(Pool<T, U> *tpool)
    {
      while (true)
	{
	  tpool->queueLock.lock();
	  while (tpool->listWork.size() == 0 && !tpool->queueShutdown)
	    tpool->queueNotEmpty.wait(tpool->queueLock);
	  if (tpool->queueShutdown)
	    {
	      tpool->queueLock.unlock();
	      pthread_exit(0);
	    }
	  Work<T, U>	&work = (tpool->listWork.front());
	  tpool->listWork.pop_front();
	  if (!tpool->doNotBlockWhenFull &&
	      tpool->listWork.size() == (tpool->maxQueueSize - 1))
	    tpool->queueNotFull.broadcast();
	  if (tpool->listWork.size() == 0)
	    tpool->queueEmpty.signal();
	  tpool->queueLock.unlock();
	  work();
	}
    }
  };
};
#endif /* THREADPOOL_HH_ */
