/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <hherba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:35 by iait-bel          #+#    #+#             */
/*   Updated: 2022/07/22 21:19:27 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int is_died(t_philo *philos, t_data *data)
{
	int i;

	i = 0;
	while(i < data->num_of_philo)
	{
		if((between_times(data->start_time) - philos[i].last_meal) > data->time_to_die)
		{
			printf("died\n");
			printf("my time :%lu\n", my_time());
			printf("between times : %lu\n", between_times(data->start_time));
			printf("last meal : %lu\n", philos[i].last_meal);
			printf("time to die : %d\n", data->time_to_die);
			printf("philo li mat : %d", philos[i].nbr);
			return(1);
		}
		i++;
	}
	// exit(0);
	return (0);
}
