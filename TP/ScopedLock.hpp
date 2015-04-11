#ifndef __SCOPEDLOCK_HPP__
# define __SCOPEDLOCK_HPP__

#include <pthread.h>

class ScopedLock
{
  pthread_mutex_t	*_mutex;

public:
  ScopedLock(pthread_mutex_t *mutex);
  virtual ~ScopedLock();
};

#endif
