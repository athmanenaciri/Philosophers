/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:10:35 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/19 13:51:10 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_data
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
}t_data;

typedef struct s_philo
{
	int	nbr;
	int	meals;
	pthread_t thread;
	pthread_mutex_t left;
	pthread_mutex_t *right;
	t_data	*data;
	
}t_philo;

int	ft_atoi(char *str, int *nbr);
int	create_philo(t_data *data);

#endif
