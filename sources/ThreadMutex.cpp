//
// ThreadMutex.cpp for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/sources
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 15:19:07 2013 lambert kevin
// Last update Mon Oct  7 12:45:41 2013 lambert kevin
//

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
    return (pthread_mutex_lock(&_m) == 0 ? true : false);
  }

  bool			Mutex::unlock()
  {
    return (pthread_mutex_unlock(&_m) == 0 ? true : false);
  }

  bool			Mutex::trylock()
  {
    return (pthread_mutex_trylock(&_m) == 0 ? true : false);
  }

  Mutex			*Mutex::createMutex()
  {
    return (new Mutex);
  }

  pthread_mutex_t	&Mutex::getMutex()  // Can do better...
  {
    return (_m);
  }

  MutexGuard::MutexGuard() : Mutex()
  {
    lock();
  }

  MutexGuard::~MutexGuard()
  {
    unlock();
  }
}
