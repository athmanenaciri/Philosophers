/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:49:04 by iait-bel          #+#    #+#             */
/*   Updated: 2022/07/21 16:14:38 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_printf(t_philo *philo, char *format)
{
	pthread_mutex_lock(&philo->data->print_lock);
	printf(format, between_times(philo->data->start_time), philo->nbr);
	pthread_mutex_unlock(&philo->data->print_lock);
}
