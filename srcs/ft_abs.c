/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:14:11 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/02 17:46:58 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int val)
{
	if (val < 0)
		return (-val);
	return (val);
}
