/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:55:35 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/23 15:01:40 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time_ms)
{
	long	n;
	long	old;

	n = time_ms * 0.9;
	old = my_time();
	usleep (n);
	while ((old + time_ms)
		> my_time());
}
