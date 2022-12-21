#include "timer.hpp"

timer::timer(void)
{
	gettimeofday(&(this->_time), NULL);
}

timer::timer(timer const & src): _time(src._time)
{
	return ;
}

timer::~timer(void)
{
	return ;
}

timer &	timer::operator=(timer const & rhs)
{
	if (this != &rhs)
		this->_time = rhs._time;
	return (*this);
}

unsigned long timer::diff(void)
{
	struct timeval now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - _time.tv_sec) * 1000) + ((now.tv_usec - _time.tv_usec)/1000));
}
