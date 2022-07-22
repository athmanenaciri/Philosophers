/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:34:40 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/22 21:18:37 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo*)ptr;
	if((philo->nbr % 2) == 0)
		usleep(10);
	while(1)
	{
		ft_printf(philo, " %lu %d is thinking\n");	
		pthread_mutex_lock(&philo->left);
		ft_printf(philo, " %lu %d has taken a fork\n");

		pthread_mutex_lock(philo->right);
		ft_printf(philo, " %lu %d has taken a fork\n");

		ft_printf(philo, " %lu %d is eating\n");
		philo->last_meal = between_times(philo->data->start_time);
		ft_usleep(philo->data->time_to_eat);
		philo->meals += 1;

		pthread_mutex_unlock(&philo->left);
		pthread_mutex_unlock(philo->right);

		ft_printf(philo, " %lu %d is sleeping\n");
		ft_usleep(philo->data->time_to_sleep);
		
		//ft_printf("timestamp_in_ms %d died\n", philo->nbr);
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
	pthread_mutex_init(&data->print_lock, NULL);  //ache kadir function? odyalache dik NULL.
	i= 0;
	while(i < num)
	{
		philos[i].last_meal = 0;
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		i++;
	}
	i = 0;
	while(!is_died(philos, data));
	return(0);
}
