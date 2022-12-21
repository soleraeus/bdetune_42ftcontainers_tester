#ifndef TIMER_HPP
# define TIMER_HPP
# include <sys/time.h>
# include <cstddef>

class timer
{
	public:
		timer(void);
		timer(timer const & src);
		~timer(void);

		timer &	operator=(timer const & rhs);

		unsigned long	diff(void);
	
	private:
		struct timeval	_time;
};

#endif
