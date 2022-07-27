/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:04 by iait-bel          #+#    #+#             */
/*   Updated: 2022/07/27 15:01:37 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_printf(t_philo *philo, char *format)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (philo->data->stop == 0)
		printf(format, between_times(philo->data->start_time), philo->nbr);
	pthread_mutex_unlock(&philo->data->print_lock);
}
