/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <hherba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:35 by iait-bel          #+#    #+#             */
/*   Updated: 2022/07/27 15:00:42 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	is_died(t_philo *philos, t_data *data)
{
	int	i;
	int	is_done;

	is_done = (data->num_of_meals != -1);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (data->num_of_meals != -1)
		{
			if (philos[i].meals >= data->num_of_meals)
				is_done *= 1;
			else
				is_done *= 0;
		}
		if ((between_times(data->start_time)
				- philos[i].last_meal) > data->time_to_die)
		{
			printf (" %lu %d died\n", between_times(data->start_time),
				philos->nbr);
			data->stop = 1;
			return (1);
		}
		i++;
	}
	return (usleep(10), is_done);
}
