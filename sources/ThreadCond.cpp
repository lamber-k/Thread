//
// ThreadCond.cpp for thread in /home/lamber_k/Dropbox/Projects/module_4e_sem/plazza/sources
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Mon Apr 15 14:22:56 2013 lambert kevin
// Last update Thu Apr 18 10:09:26 2013 lambert kevin
//

#include	"ThreadCond.hh"

namespace	Thread
{
  Cond::Cond()
  {
    pthread_cond_init(&_c, 0);
  }

  Cond::~Cond()
  {

  }

  bool	Cond::broadcast()
  {
    if (pthread_cond_broadcast(&_c) != 0)
      return (false);
    return (true);
  }

  bool	Cond::signal()
  {
    if (pthread_cond_signal(&_c) != 0)
      return (false);
    return (true);
  }

  bool	Cond::wait(Mutex &m)
  {
    if (pthread_cond_wait(&_c, &m.getMutex()) != 0)
      return (false);
    return (true);
  }

  Cond	*Cond::createCond()
  {
    return (new Cond());
  }
};
