/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_topos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:22:12 by julboyer          #+#    #+#             */
/*   Updated: 2021/12/28 13:12:11 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_top(t_data *data, t_stack *current, t_instructions **list,
	int stack_index)
{
	int i;
	int j;
	t_stack *tmp;

	i = 0;
	tmp = data->stack[stack_index];
	while (tmp != current && ++i)
		tmp = tmp->next;
	j = 0;
		printf("to top %d, %d\n", i < data->med[stack_index], data->med[stack_index]);
	if ((i < data->med[stack_index]) && i != 1)
	{
		while (j++ < i)
			ft_rotate(&data->stack[stack_index], list, stack_index);
	}
	else if (i == 1)
		swap(&data->stack[stack_index], list, stack_index);
	else if (i)
	{
		i = data->size[stack_index] - i;
		printf("TEST to top %d\n", i);
		while (j++ < i)
			ft_reverse_rotate(&data->stack[stack_index], list, stack_index);
		return (i + 1);
	}
	return (i);
}

int	to_second(t_data *data, t_stack *current, t_instructions **list,
	int stack_index)
{
	int i;
	int j;
	t_stack *tmp;

	i = 0;
	tmp = data->stack[stack_index];
	while (tmp != current && ++i)
		tmp = tmp->next;
	j = 1;
	if ((i <= data->med[stack_index]) && (i != 0))
		while (j++ < i)
			ft_rotate(&data->stack[stack_index], list, stack_index);
	else if (i == 0)
	{
		swap(&data->stack[stack_index], list, stack_index);
		return (1);
	}
	else if (i != 1)
	{
		i = data->size[stack_index] - i + 1;
		while (j++ < i)
			ft_reverse_rotate(&data->stack[stack_index], list, stack_index);
		return (i);
	}
	return (i - 1);
}

void	swap_rotate(t_data *data, t_instructions **list, int index)
{
	swap(&data->stack[index], list, index);
	ft_rotate(&data->stack[index], list, index);
}

void	swap_rrotate(t_data *data, t_instructions **list, int index)
{
	swap(&data->stack[index], list, index);
	if ((index == A && is_sorted(data->stack[index])) || (index == B && is_reverse_sorted(data->stack[index])))
		ft_reverse_rotate(&data->stack[index], list, index);
}
