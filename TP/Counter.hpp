#ifndef __COUNTER_HPP__
# define __COUNTER_HPP__

# include "IMutex.hpp"

class	Counter : IMutex
{
  int			_val;
  pthread_mutex_t	_mutex;

public:
  Counter(int val);
  virtual ~Counter();

  void			lock();
  void			unlock();
  bool			trylock();

  int			getVal();
  pthread_mutex_t	*getMutex();
  void			setVal(int val);
};

#endif
