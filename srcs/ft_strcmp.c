/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:02:51 by julboyer          #+#    #+#             */
/*   Updated: 2021/07/14 15:02:09 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	x;

	x = 0;
	while ((unsigned char)s1[x] == (unsigned char)s2[x]
		&& (unsigned char)s1[x] && (unsigned char)s2[x])
		x++;
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}
