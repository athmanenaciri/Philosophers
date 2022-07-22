#include "philo.h"

void ft_usleep(long	time_ms)
{
	long n;
	long old;

	n = time_ms * 0.9;
	old = my_time();
	usleep(n);
	while((old + time_ms) > my_time());
}
