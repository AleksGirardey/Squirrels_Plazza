
#include <iostream>
#include "Counter.hpp"
#include "ScopedLock.hpp"

void*		increment_counter(void* n)
{
  ScopedLock	sl(reinterpret_cast<Counter *>(n)->getMutex());
  
  for (int i = 0; i < 100000; i++)
    reinterpret_cast<Counter *>(n)->setVal(reinterpret_cast<Counter *>(n)->getVal() + 1);
  return NULL;
}

int		main()
{
  pthread_t		thr1;
  pthread_t		thr2;
  pthread_t		thr3;
  Counter		n(0);

  pthread_create(&thr1, NULL, &increment_counter, &n);
  pthread_create(&thr2, NULL, &increment_counter, &n);
  pthread_create(&thr3, NULL, &increment_counter, &n);

  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);
  std::cout << n.getVal() << std::endl;
  return (1);
}
