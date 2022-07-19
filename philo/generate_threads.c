#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;

	while(1)
	{
		printf(" %d has taken a fork\n" ,philo->nbr);
		printf(" %d is eating\n" ,philo->nbr);
		usleep(philo->data->time_to_eat * 1000);
		printf(" %d is sleeping\n" ,philo->nbr);
		usleep(philo->data->time_to_sleep * 1000);
		printf(" %d is thinking\n", philo->nbr);
		printf(" %d died\n", philo->nbr);
	}
	return(NULL);
}

int	create_philo(t_data *data)
{
	int num;
	int i;

	t_philo *philos;
	num = data->num_of_philo;
	philos = malloc(sizeof(t_philo) * num);
	if(philos == NULL)
		return(1);
	i = 0;
	while(i < num)
	{
		philos[i].nbr = i+1;
		philos[i].meals = 0;
		philos[i].data = data;

		pthread_mutex_init(&philos[i].left, NULL);
		if(i != 0)
		{
			philos[i].right = &philos[i-1].left;
			pthread_mutex_init(&philos[i-1].right, NULL);
		}
		else
		{
			philos[i].right = &philos[philos->data->num_of_philo].left;
			pthread_mutex_init(&philos[i-1].right, NULL);
		}

		//protect thread 
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);

		i++;
	}
	return(0);
}



int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
int pthread_mutex_lock(pthread_mutex_t *mutex);