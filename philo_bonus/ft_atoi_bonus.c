/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaciri <anaciri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:56:36 by anaciri           #+#    #+#             */
/*   Updated: 2022/07/27 19:44:51 by anaciri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_it(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}	
	return (0);
}

int	check_edges(long n)
{
	if (n > 2147483647)
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str, int *nbr)
{
	int		i;
	long	res;

	if (ft_check_it(str))
		return (1);
	res = 0;
	i = 0;
	while (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	*nbr = res;
	return (check_edges(res));
}
