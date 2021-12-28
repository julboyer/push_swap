/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:17:16 by julboyer          #+#    #+#             */
/*   Updated: 2021/07/15 14:14:03 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			x++;
		}
		if (s[i])
			i++;
	}
	return (x);
}

static int	ft_wordlen(char const *s, char c)
{
	int	x;

	x = 0;
	while (s[x] && s[x] != c)
		x++;
	return (x);
}

static char	**ft_free(char **s, int x)
{
	int	i;

	i = 0;
	while (i < x)
		free(s[i++]);
	free(s);
	return (NULL);
}

char	**ft_split2(char const *s, char c, int words, char **res)
{
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 0;
	while (s[i] && x < words)
	{
		if (s[i] != c)
		{
			res[x] = malloc(sizeof(char) * (ft_wordlen(&s[i], c) + 1));
			if (!res)
				return (ft_free(res, x));
			j = 0;
			while (s[i] && s[i] != c)
				res[x][j++] = s[i++];
			res[x++][j] = '\0';
		}
		if (s[i])
			i++;
	}
	res[x] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	words = ft_wordcount(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res = ft_split2(s, c, words, res);
	return (res);
}
