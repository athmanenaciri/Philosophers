#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;
	if((philo->nbr % 2) == 0)
		usleep(100);
	while(1)
	{
		printf(" %d is thinking\n", philo->nbr);
		
		pthread_mutex_lock(&philo->left);
		printf(" %d has taken a fork\n" ,philo->nbr);

		pthread_mutex_lock(philo->right);
		printf(" %d has taken a fork\n" ,philo->nbr);

		printf(" %d is eating\n" ,philo->nbr);
		usleep(philo->data->time_to_eat * 1000);

		pthread_mutex_unlock(&philo->left);
		pthread_mutex_unlock(philo->right);

		printf(" %d is sleeping\n" ,philo->nbr);
		usleep(philo->data->time_to_sleep * 1000);
		
		//printf(" %d died\n", philo->nbr);
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
			philos[i].right = &philos[i-1].left;
		else
			philos[i].right = &philos[philos->data->num_of_philo - 1].left;
		//protect thread 

		i++;
	}
	i= 0;
	while(i < num)
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
	return(0);
}

int pthread_mutex_lock(pthread_mutex_t *mutex);