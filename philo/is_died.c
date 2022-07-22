/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hherba <hherba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:35 by iait-bel          #+#    #+#             */
/*   Updated: 2022/07/22 14:57:34 by hherba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int is_died(t_philo *philos, t_data *data)
{
	int i;

	i = 0;
	while(i < data->num_of_philo)
	{
		if((philos[i].last_meal - my_time()) > data->time_to_eat)
		{
			printf("died");
			return(1);
		}
		//printf("#%lu#\n", philos[i].last_meal);
		//printf("(%lu)", (philos[i].last_meal - my_time()));
		i++;
	}
	// exit(0);
	return (0);
}
