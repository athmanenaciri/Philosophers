/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_times.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:35:37 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/20 19:44:33 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long	between_times(long before)
{
	long	now;
	long	def;

	now = my_time();
	def = now - before;
	return(def);
}
