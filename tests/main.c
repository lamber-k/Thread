#include	<iostream>
#include	"ThreadPool.hpp"

Thread::Mutex	m;

void	foo(int i)
{
  m.lock();
  std::cout << "current value: " << i << std::endl;
  m.unlock();
}

int					main()
{
  Thread::Pool<void (*)(int), int>	pool(4, 10, false);
  int					i = 0;

  pool.run();
  while (i < 10000)
    {
      Thread::Work<void (*)(int), int>	work(&foo, i);

      pool.addWork(work);
      ++i;
    }
  pool.stop(true);
  return (0);
}
