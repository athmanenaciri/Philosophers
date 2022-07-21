/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:34:40 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/20 22:53:14 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;
	if((philo->nbr % 2) == 0)
		usleep(100);
	while(1)
	{
		printf(" %lu %d is thinking\n", between_times(philo->data->start_time), philo->nbr);	
		pthread_mutex_lock(&philo->left);
		printf(" %lu %d has taken a fork\n", between_times(philo->data->start_time), philo->nbr);

		pthread_mutex_lock(philo->right);
		printf("%lu %d has taken a fork\n", between_times(philo->data->start_time), philo->nbr);

		printf(" %lu %d is eating\n", between_times(philo->data->start_time), philo->nbr);
		usleep(philo->data->time_to_eat * 1000);

		pthread_mutex_unlock(&philo->left);
		pthread_mutex_unlock(philo->right);

		printf(" %lu %d is sleeping\n", between_times(philo->data->start_time), philo->nbr);
		usleep(philo->data->time_to_sleep * 1000);
		
		//printf("timestamp_in_ms %d died\n", philo->nbr);
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
		pthread_mutex_init(&philos[i].left, NULL);  //ache kadir function? odyalache dik NULL.
		if(i != 0)
			philos[i].right = &philos[i-1].left;
		else
			philos[i].right = &philos[philos->data->num_of_philo - 1].left;
		//protect thread 
		i++;
	}
	data->start_time = my_time();
	i= 0;
	while(i < num)
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
	return(0);
}

int pthread_mutex_lock(pthread_mutex_t *mutex);
