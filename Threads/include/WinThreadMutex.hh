//
// ThreadMutex.hh for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/include
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 13:07:15 2013 lambert kevin
// Last update Mon Oct  7 12:50:02 2013 lambert kevin
//

#ifndef		WINTHREADMUTEX_HH_
# define	WINTHREADMUTEX_HH_

# include	<windows.h>

namespace 	Thread
{
  class DECLPORT MutexBase
  {
  protected:
	CRITICAL_SECTION	_m;

  public:
    MutexBase()
    {
		InitializeCriticalSection(&_m);
    }
    virtual ~MutexBase()
    {
		DeleteCriticalSection(&_m);
    }
  };

  class	DECLPORT 		Mutex : protected MutexBase
  {
    friend class Cond;
  public:
    Mutex();
    virtual ~Mutex();
    virtual bool		lock();
    virtual bool		unlock();
    virtual bool		trylock();
    static Thread::Mutex	*createMutex();

  protected:
    CRITICAL_SECTION	&getMutex();
  };

  class	DECLPORT 	MutexGuard
  {
	  friend		Mutex;
	  Mutex			&_locker;

  public:
    MutexGuard(Mutex &);
    virtual ~MutexGuard();
  };
};
#endif /* WINTHREADMUTEX_HH_ */
