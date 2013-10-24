#ifndef		THREADS_HPP
#define		THREADS_HPP

# include	"ThreadPlatform.hh"

# if defined(WIN32)
#  include	"WinThreads.hpp"
# elif defined(linux)
#  include	"LinuxThreads.hpp"
# else
#  error "Unsupported Operating system"
# endif

#endif		/* THREADS_HH */