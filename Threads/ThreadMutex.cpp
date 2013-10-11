//
// ThreadMutex.cpp for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/sources
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 15:19:07 2013 lambert kevin
// Last update Fri Oct 11 17:14:03 2013 lambert kevin
//

#if defined(WIN32)
# include	<StdAfx.h>
#endif
#include	"ThreadMutex.hh"

namespace Thread
{
  Mutex::Mutex() : MutexBase()
  {
  }

  Mutex::~Mutex()
  {
  }

  bool			Mutex::lock()
  {
#if defined(WIN32)
	  EnterCriticalSection(&_m);
	  return (true);
#elif defined(linux)
	  return (pthread_mutex_lock(&_m) == 0 ? true : false);
#else
# error "Unsupported Operating system"
#endif
  }

  bool			Mutex::unlock()
  {
#if defined(WIN32)
	  LeaveCriticalSection(&_m);
	  return (true);
#elif defined(linux)
    return (pthread_mutex_unlock(&_m) == 0 ? true : false);
#else
# error "Unsupported Operating system"
#endif
  }

  bool			Mutex::trylock()
  {
#if defined(WIN32)
	  TryEnterCriticalSection(&_m);
	  return (true);
#elif defined(linux)
    return (pthread_mutex_trylock(&_m) == 0 ? true : false);
#else
# error "Unsupported Operating system"
#endif
  }

  Mutex			*Mutex::createMutex()
  {
    return (new Mutex);
  }


#if defined(WIN32)
  CRITICAL_SECTION	&Mutex::getMutex()  // Can do better...
#elif defined(linux)
  pthread_mutex_t	&Mutex::getMutex()  // Can do better...
#else
# error "Unsupported Operating system"
#endif
  {
    return (_m);
  }

  MutexGuard::MutexGuard(Mutex &m) :
	_locker(m)
  {
    _locker.lock();
  }

  MutexGuard::~MutexGuard()
  {
	_locker.unlock();
  }
}
