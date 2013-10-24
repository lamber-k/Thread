//
// Thread.hh for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/include
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 12:27:48 2013 lambert kevin
// Last update Mon Oct  7 15:05:26 2013 lambert kevin
//

#ifndef		WINTHREAD_HPP_
# define	WINTHREAD_HPP_

# include	<Windows.h>
# include	<tchar.h>
# include	<strsafe.h>
# include	"StdAfx.h"

template <typename T, typename U>
class		Threads
{
  U						_func;
  T						_param;
  HANDLE				_th;
  DWORD					_thid;
  bool					_detached;
  bool					_activated;

public:
   Threads(U func, T param = 0) :
    _func(func), _param(param), _detached(false), _activated(false)
  {
  }

   virtual ~Threads()
  {
	cancel();
  }

   bool		run()
  {
    if (_activated)
      return (false);
	if ((_th = CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(_func),
							reinterpret_cast<LPVOID>(_param), 0, &_thid)) == NULL)
      return (false);
    _activated = true;
    return (true);
  }

   bool		cancel()
  {
    if (_activated)
		if (!CloseHandle(_th))
			return (false);
    _activated = false;
	return (true);
  }

   bool		join(U *ret = 0)
  {
    if (_detached || !_activated)
      return (false);
	if (!WaitForSingleObject(_th, INFINITE))
      return (false);
    _activated = false;
    return (true);
  }

   bool		setDetachState()
  {
	return (false);
  }

   bool		unsetDetachState()
  {
	return (false);
  }

   bool		getDetatchState() const
  {
    return (false);
  }
   bool		isActivated() const
  {
    return (_activated);
  }
};

#endif /* WINTHREAD_HPP_ */
