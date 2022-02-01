/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psw_topos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:22:12 by julboyer          #+#    #+#             */
/*   Updated: 2022/01/30 13:19:08 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_top(t_data *data, t_stack *current, t_instructions **list,
	int stack_index)
{
	int i;
	int j;

	i = get_pivot_pos(data, current->frame, stack_index);
//	printf("i %d\n", i);
	j = 0;
	if (i == 1)
		swap(&data->stack[stack_index], list, stack_index);
	else if ((i <= data->med[stack_index]))
	{
		while (j++ < i)
			ft_rotate(&data->stack[stack_index], list, stack_index);
	}
	else if (i)
	{
		i = data->size[stack_index] - i;
		while (j++ < i)
			ft_reverse_rotate(&data->stack[stack_index], list, stack_index);
//		printf("to top reverse j%d : ", j);
//		print_stack(data, stack_index);
		return (i);
	}
	return (i);
}

int	to_second(t_data *data, t_stack *current, t_instructions **list,
	int stack_index)
{
	int i;
	int j;

	i = get_pivot_pos(data, current->frame, stack_index);
	j = 0;
	if (i == 0)
	{
		swap(&data->stack[stack_index], list, stack_index);
		return (1);
	}
	if ((i - 1 <= data->med[stack_index]))
	{
		while (j++ < i - 1)
			ft_rotate(&data->stack[stack_index], list, stack_index);
	}
	else
	{
		i = data->size[stack_index] - i + 1;
		while (j++ < i)
			ft_reverse_rotate(&data->stack[stack_index], list, stack_index);
		return (i + 1);
	}
	return (i);
}

void	swap_rotate(t_data *data, t_instructions **list, int index)
{
	swap(&data->stack[index], list, index);
		ft_rotate(&data->stack[index], list, index);
}

void	swap_rrotate(t_data *data, t_instructions **list, int index)
{
	swap(&data->stack[index], list, index);
	ft_reverse_rotate(&data->stack[index], list, index);
}

int	to_pos(t_data *data, int move, t_instructions **list, int stack_index)
{
	int sign;
	int i;

	if (ft_abs(move) > data->med[stack_index])
	{
		if (move < 0)
			move = move + data->size[stack_index];
		else
			move = move - data->size[stack_index];
	}
	if (move < 0)
		sign = -1;
	else
		sign = 0;
	i = 0;
	if (sign)
	{
		while (i++ < ft_abs(move))
			ft_rotate(&data->stack[stack_index], list, stack_index);
	}
	else if (move > 0)
	{
		while (i++ < move)
			ft_reverse_rotate(&data->stack[stack_index], list, stack_index);
	}
	return (move);
}
