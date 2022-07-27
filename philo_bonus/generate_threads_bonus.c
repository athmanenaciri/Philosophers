/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_threads_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:34:40 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/24 18:50:46 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine(t_philo *philo)
{
	if (philo->nbr % 2 == 0)
	{
		ft_printf(philo, " %lu %d is thinking\n");
		pthread_mutex_lock(philo->right);
		ft_printf(philo, " %lu %d has taken a fork\n");
		pthread_mutex_lock(&philo->left);
		ft_printf(philo, " %lu %d has taken a fork\n");
	}
	else
	{
		ft_printf(philo, " %lu %d is thinking\n");
		pthread_mutex_lock(&philo->left);
		ft_printf(philo, " %lu %d has taken a fork\n");
		pthread_mutex_lock(philo->right);
		ft_printf(philo, " %lu %d has taken a fork\n");
	}
}

void	*routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (1)
	{
		ft_routine(philo);
		ft_printf(philo, " %lu %d is eating\n");
		philo->last_meal = between_times(philo->data->start_time);
		ft_usleep(philo->data->time_to_eat);
		philo->meals += 1;
		pthread_mutex_unlock(&philo->left);
		pthread_mutex_unlock(philo->right);
		ft_printf(philo, " %lu %d is sleeping\n");
		ft_usleep(philo->data->time_to_sleep);
	}
	return (NULL);
}

void	ft_create_philo(int num, t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philos[i].nbr = i + 1;
		philos[i].meals = 0;
		philos[i].data = data;
		pthread_mutex_init(&philos[i].left, NULL);
		if (i != 0)
			philos[i].right = &philos[i - 1].left;
		else
			philos[i].right = &philos[philos->data->num_of_philo - 1].left;
		i++;
	}
}

int	ft_destroy(t_philo *philos)
{
	int	i;
	int	num;

	i = 0;
	num = philos->data->num_of_philo;
	while (i < num)
	{
		pthread_mutex_destroy(&philos[i].left);
		i++;
	}
	pthread_mutex_destroy(&philos->data->print_lock);
	free(philos);
	return (1);
}

int	create_philo(t_data *data)
{
	int		num;
	int		i;
	t_philo	*philos;

	num = data->num_of_philo;
	philos = malloc(sizeof(t_philo) * num);
	if (philos == NULL)
		return (1);
	ft_create_philo(num, philos, data);
	data->start_time = my_time();
	pthread_mutex_init(&data->print_lock, NULL);
	i = 0;
	while (i < num)
	{
		philos[i].last_meal = 0;
		if (pthread_create (&philos[i].thread, NULL, routine, &philos[i]) == -1)
			ft_destroy(philos);
		i++;
	}
	i = 0;
	while (!is_died(philos
			, data));
	ft_destroy(philos);
	return (0);
}
