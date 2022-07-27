/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:02:23 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/23 17:00:40 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long	my_time(void)
{
	struct timeval	time;
	long			mlsec;

	gettimeofday(&time, NULL);
	mlsec = time.tv_sec * 1000;
	mlsec = mlsec + (time.tv_usec / 1000);
	return (mlsec);
}
