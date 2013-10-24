//
// ThreadCond.cpp for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/sources
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 14:22:56 2013 lambert kevin
// Last update Thu Oct 24 19:13:35 2013 lambert kevin
//

#include	"ThreadCond.hh"

namespace	Thread
{
  Cond::Cond()
  {
#if defined(WIN32)
    InitializeConditionVariable(&_c);
#elif defined(linux)
    pthread_cond_init(&_c, 0);
#else
# error "Unsupported Operating system"
#endif
  }

  Cond::~Cond()
  {

  }

  bool	Cond::broadcast()
  {
#if defined(WIN32)
    WakeAllConditionVariable(&_c);
#elif defined(linux)
    if (pthread_cond_broadcast(&_c) != 0)
      return (false);
#else
#error "Unsupported Operating system"
#endif
    return (true);
  }

  bool	Cond::signal()
  {
#if defined(WIN32)
    WakeConditionVariable(&_c);
#elif defined(linux)
    if (pthread_cond_signal(&_c) != 0)
      return (false);
#else
#error "Unsupported Operating system"
#endif
    return (true);
  }

  bool	Cond::wait(Mutex &m)
  {
#if defined(WIN32)
    if (SleepConditionVariableCS(&_c, &m.getMutex(), INFINITE) != 0)
#elif defined(linux)
      if (pthread_cond_wait(&_c, &m.getMutex()) != 0)
#else
#error "Unsupported Operating system"
#endif
	return (false);
    return (true);
  }

  Cond	*Cond::createCond()
  {
    return (new Cond());
  }
}
