/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:44:35 by iait-bel          #+#    #+#             */
/*   Updated: 2022/07/21 17:55:57 by iait-bel         ###   ########.fr       */
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
	//	printf("#%lu#\n", philos[i].last_meal);
		//printf("(%lu)", (philos[i].last_meal - my_time()));
		i++;
	}
	// exit(0);
	return (0);
}
