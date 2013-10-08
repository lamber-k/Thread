//
// ThreadWork.hpp for thread in /home/lamber_k/module_4e_sem/plazza/plazza
//
// Made by lambert kevin
// Login   <lamber_k@epitech.net>
//
// Started on  Tue Apr 16 11:56:49 2013 lambert kevin
// Last update Sun Apr 21 00:39:03 2013 lambert kevin
//

#ifndef THREADWORK_HPP_
# define THREADWORK_HPP_

namespace	Thread
{
  template <typename T, typename U>
  class		Work
  {
    T		_func;
    U		_arg;

  public:
    Work(T func, U arg) : _func(func), _arg(arg) {}
    virtual ~Work() {}
    void	operator()()
    {
      _func(_arg);
    }
  };

};

#endif /* THREADWORK_HPP_ */
