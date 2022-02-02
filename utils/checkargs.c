/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:14:21 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/02 16:56:20 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ispresent(t_stack *stack, long int number)
{
	while (stack->next)
	{
		if (stack->frame == number)
			return (-1);
		stack = stack->next;
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

int	str_isnum(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	skip_zero(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	return (i);
}

int	checkargs(const char *s, t_stack **stack, char ***ret_split)
{
	char		**split;
	t_stack		*tmp;
	int			i;
	int			j;

	split = ft_split(s, ' ');
	*ret_split = split;
	i = 0;
	while (split[i])
	{
		j = skip_zero(&split[i][0]);
		if (ft_strlen(&split[i][j]) > 10)
			return (-1);
		if (str_isnum(&split[i][j]))
			return (-1);
		ft_pswadd_back(stack, ft_pswnew(ft_atol(split[i])));
		tmp = ft_pswlast(*stack);
		if (tmp->frame > INT_MAX || tmp->frame < INT_MIN)
			return (-1);
		if (ispresent(*stack, tmp->frame))
			return (-1);
		i++;
	}
	split = split_free(split);
	return (0);
}
