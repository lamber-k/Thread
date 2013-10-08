//
// Thread.hh for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/include
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 12:27:48 2013 lambert kevin
// Last update Mon Oct  7 15:05:26 2013 lambert kevin
//

#ifndef		THREAD_HH_
# define	THREAD_HH_

# include	<pthread.h>

template <typename T, typename U>
class Threads
{
  U			_func;
  T			_param;
  pthread_t		_th;
  pthread_attr_t	_attr;
  bool			_detached;
  bool			_activated;

public:
  Threads(U func, T param = 0) :
    _func(func), _param(param), _detached(false), _activated(false)
  {
    pthread_attr_init(&_attr);
  }

  virtual ~Threads()
  {
    if (_activated)
      pthread_cancel(_th);
  }

  bool		run()
  {
    if (_activated)
      return (false);
    if (pthread_create(&_th, &_attr, reinterpret_cast<void *(*)(void *)>(_func), _param) != 0)
      return (false);
    _activated = true;
    return (true);
  }

  bool		cancel()
  {
    if (_activated)
      if (pthread_cancel(_th) != 0)
	return (false);
    _activated = false;
  }

  bool		join(U *ret = 0)
  {
    if (_detached || !_activated)
      return (false);
    if (pthread_join(_th, reinterpret_cast<void **>(&ret)) != 0)
      return (false);
    _activated = false;
    return (true);
  }

  bool		setDetachState()
  {
    if (pthread_attr_setdetachstate(&_attr, PTHREAD_CREATE_DETACHED) != 0)
      return (false);
    _detached = true;
    return (true);
  }

  bool		unsetDetachState()
  {
    if (pthread_attr_setdetachstate(&_attr, PTHREAD_CREATE_JOINABLE) != 0)
      return (false);
    _detached = false;
    return (true);
  }

  bool		getDetatchState() const
  {
    return (_detached);
  }
  bool		isActivated() const
  {
    return (_activated);
  }
};

#endif /* THREAD_HH_ */
