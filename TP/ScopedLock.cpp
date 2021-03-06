#include "ScopedLock.hpp"

ScopedLock::ScopedLock(pthread_mutex_t *mutex) : _mutex(mutex)
{
  pthread_mutex_lock(_mutex);
}

ScopedLock::~ScopedLock()
{
  pthread_mutex_unlock(_mutex);
}
