#ifndef		THREAD_PLATFORM_HH
# define	THREAD_PLATFORM_HH

# if defined(WIN32)
#  define	DECLEXPORT	__declspec(dllexport)
#  define	DECLIMPORT	__declspec(dllimport)
#  if defined(THREADS_EXPORTS)
#   define	DECLPORT	DECLEXPORT
#  else
#   define	DECLPORT	DECLIMPORT
#  endif
# elif defined(linux)
#  define	DECLPORT
# else
#  error	"Unsupported Operating system"
# endif

#endif