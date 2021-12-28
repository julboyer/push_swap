/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 11:26:32 by julboyer          #+#    #+#             */
/*   Updated: 2021/07/15 12:09:14 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		x;

	x = 0;
	dup = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	while (s1[x])
	{
		dup[x] = s1[x];
		x++;
	}
	dup[x] = '\0';
	return (dup);
}
