#ifndef		THREAD_COND_HH
#define		THREAD_COND_HH

# include	"ThreadPlatform.hh"

# if defined(WIN32)
#  include	"WinThreadCond.hh"
# elif defined(linux)
#  include	"LinuxThreadCond.hh"
# else
#  error "Unsupported Operating system"
# endif

#endif		/* THREAD_COND_HH */