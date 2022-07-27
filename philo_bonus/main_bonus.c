/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:11:51 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/27 19:47:34 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup_data(t_data *data, char **av, int ac)
{
	if (ft_atoi(av[1], &data->num_of_philo))
		return (1);
	if (ft_atoi(av[2], &data->time_to_die))
		return (1);
	if (ft_atoi(av[3], &data->time_to_eat))
		return (1);
	if (ft_atoi(av[4], &data->time_to_sleep))
		return (1);
	if (ac == 5)
		data->num_of_meals = -1;
	else
		if (ft_atoi(av[5], &data->num_of_meals))
			return (1);
	if (data->num_of_meals == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.stop = 0;
	if (ac > 6 || ac < 5)
		return (1);
	if (setup_data(&data, av, ac))
		return (1);
	data.start_time = my_time();
	if (create_philo(&data))
		return (1);
	return (0);
}
