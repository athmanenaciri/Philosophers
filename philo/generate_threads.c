#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;

	printf(" %d has taken a fork\n" ,philo->nbr);
	printf(" %d is eating\n" ,philo->nbr);
	usleep();
	printf(" %d is sleeping\n" ,philo->nbr);
	printf(" %d is thinking\n", philo->nbr);
	printf(" %d died\n", philo->nbr);

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
		//protect thread 
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
	return(0);
}
