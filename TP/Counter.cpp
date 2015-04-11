#include "Counter.hpp"

Counter::Counter(int val) : _val(val)
{
  pthread_mutex_init(&_mutex, NULL);
}

Counter::~Counter()
{

}

void		Counter::lock()
{
  pthread_mutex_lock(&(this->_mutex));
}

void		Counter::unlock()
{
  pthread_mutex_unlock(&(this->_mutex));
}

bool		Counter::trylock()
{
  return (pthread_mutex_trylock(&(this->_mutex)));
}

int		Counter::getVal()
{
  return (_val);
}

void		Counter::setVal(int val)
{
  this->_val = val;
}

pthread_mutex_t	*Counter::getMutex()
{
  return (&(this->_mutex));
}
