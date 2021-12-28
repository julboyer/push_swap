/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:14:21 by julboyer          #+#    #+#             */
/*   Updated: 2021/12/27 16:56:24 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ispresent(t_stack *stack)
{
	int	number;

	number = stack->frame;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->frame == number)
			return (-1);
	}
	return (0);
}

char	**split_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

int	checkargs(const char *s, t_stack **stack)
{
	char **split;
	t_stack *tmp;
	int i;
	int j;

	split = ft_split(s, ' ');
	i = 0;
	while (split[i])
	{
		j = 0;
		if (split[i][j] == '-' || *s == '+')
			j++;
		while (split[i][j] == '0')
			j++;
		if (ft_strlen(&split[i][j]) > 10)
			return (-1);
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return (-1);
			j++;
		}
		ft_pswadd_back(stack, ft_pswnew(ft_atol(split[i])));
		tmp = *stack;
		if (tmp->frame > INT_MAX || tmp->frame < INT_MIN)
			return(-1);
		if (ispresent(tmp))
			return (-1);
		i++;
	}
	split = split_free(split);
	return (0);
}
