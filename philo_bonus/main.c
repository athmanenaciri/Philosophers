/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:11:51 by anaciri           #+#    #+#             */
/*   Updated: 2022/06/25 17:47:05 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
	t_data data;
	
	while(ac > 6 || ac < 5)
		return(1);
	if(ft_atoi(av[1], &data.num_of_philo))
		return(1);
	if(ft_atoi(av[2], &data.time_to_die))
		return(1);
	if(ft_atoi(av[3], &data.time_to_eat))
		return(1);
	if(ft_atoi(av[4], &data.time_to_sleep))
		return(1);
	if(ac == 5)
		data.num_of_meals = -1;
	else
		if(ft_atoi(av[5], &data.num_of_meals))
			return(1);
	if(data.num_of_meals == 0)
		return(1);
	return(0);
}
