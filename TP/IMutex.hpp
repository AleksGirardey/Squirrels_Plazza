#ifndef	__IMUTEX_HPP__
# define __IMUTEX_HPP__

# include <pthread.h>

class	IMutex
{
public:
  virtual ~IMutex(){}
  virtual void	lock() = 0;
  virtual void	unlock() = 0;
  virtual bool	trylock() = 0;
};

#endif
