/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 09:48:36 by julboyer          #+#    #+#             */
/*   Updated: 2021/11/24 12:12:37 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long int	ft_atol(const char *str)
{
	int			sign;
	long int	val;
	int			x;

	x = 0;
	val = 0;
	sign = 1;
	while ((str[x] > 8 && str[x] < 14) || (str[x] == ' '))
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sign = sign * -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		val = (val * 10) + (str[x] - 48);
		x++;
	}
	return (val * sign);
}
