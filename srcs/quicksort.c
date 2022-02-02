/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:26:51 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/02 17:00:04 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_move(t_data *data, int chunk_min, int chunk_max)
{
	t_stack	*ret;

	ret = data->stack[A];
	while (ret && (ret->index >= chunk_max || ret->index < chunk_min))
	{
		ret = ret->next;
	}
	return (ret->frame);
}

void	push_number(t_data *data, int number, t_instructions **list, int index)
{
	to_pos(data, -get_pivot_pos(data, number, index), list, index);
	push(data, index, 1 - index, list);
}

void	order_start(t_data *data, t_instructions **list)
{
	int		chunk_div;
	int		i;
	int		size;

	if (is_sorted(data->stack[A]))
		return ;
	size = data->size[A];
	if (data->size[A] < 250)
		chunk_div = 5;
	else
		chunk_div = 11;
	i = 1;
	while (i <= chunk_div)
	{
		while (data->size[B] < (size * i / chunk_div) - ((i - 1)
				* size / chunk_div))
			push_number(data, first_move(data, (i - 1) * size / chunk_div, i
					* size / chunk_div), list, A);
		to_pos(data, -((i - 1) * size / chunk_div)
			- get_pivot_pos(data, data->small[A], A), list, A);
		while (data->stack[B])
			push_number(data, data->big[B], list, B);
		i++;
	}
	to_pos(data, -get_index_pos(data, 0, A), list, A);
}

void	small_sort(t_data *data, t_instructions **list)
{
	while (data->size[A] > 3)
	{
		to_pos(data, -get_pivot_pos(data, data->small[A], A), list, A);
		push(data, A, B, list);
	}
	to_pos(data, -get_pivot_pos(data, data->big[A], A) - 1, list, A);
	if (data->stack[A]->frame != data->small[A])
		swap(&data->stack[A], list, A);
	while (data->stack[B])
	{
		to_pos(data, -get_pivot_pos(data, data->big[B], B), list, B);
		push(data, B, A, list);
	}
}
