/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:43:28 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/02 17:03:00 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pswsize(t_stack *lst)
{
	int	x;

	x = 0;
	while (lst)
	{
		lst = lst->next;
		x++;
	}
	return (x);
}

int	ft_pswbig(t_stack *stack)
{
	int	i;

	if (stack)
	{
		i = stack->frame;
		while (stack)
		{
			if (i < stack->frame)
				i = stack->frame;
			stack = stack->next;
		}
		return (i);
	}
	return (0);
}

int	ft_pswsmall(t_stack *stack)
{
	int	i;

	if (stack)
	{
		i = stack->frame;
		while (stack)
		{
			if (i > stack->frame)
				i = stack->frame;
			stack = stack->next;
		}
		return (i);
	}
	return (0);
}

int	get_pivot_pos(t_data *data, int pivot, int index)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = data->stack[index];
	while (tmp && tmp->frame != pivot)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	get_index_pos(t_data *data, int index, int stack)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = data->stack[stack];
	while (tmp && tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
