#ifndef		THREAD_MUTEX_HH
# define	THREAD_MUTEX_HH

# include	"ThreadPlatform.hh"

# if defined(WIN32)
#  include	"WinThreadMutex.hh"
# elif defined(linux)
#  include	"LinuxThreadMutex.hh"
# else
#  error "Unsupported Operating system"
# endif

#endif		/* THREAD_MUTEX_HH */