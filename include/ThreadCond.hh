//
// ThreadCond.hh for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/include
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 13:13:42 2013 lambert kevin
// Last update Tue Apr 16 10:12:03 2013 lambert kevin
//

#ifndef		THREADCOND_HH_
# define	THREADCOND_HH_

# include	<pthread.h>
# include	"ThreadMutex.hh"

namespace	Thread
{
  class			Cond
  {
    pthread_cond_t	_c;

  public:
    Cond();
    virtual ~Cond();
    virtual bool	broadcast();
    virtual bool	signal();
    virtual bool	wait(Mutex &);
    static Cond		*createCond();
  };
};

#endif /* THREADCOND_HH_ */
