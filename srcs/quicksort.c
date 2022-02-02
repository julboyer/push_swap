/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:26:51 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/02 01:27:27 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *first_move(t_data *data, int chunk_min, int chunk_max)
{
	t_stack *ret;

	ret = data->stack[A];
	while (ret && (ret->index >= chunk_max || ret->index < chunk_min))
	{
		ret = ret->next;
	}
	return (ret);
}

void	order_start(t_data *data, t_instructions **list)
{
	int chunk_div;
	t_stack *first;
	int i;
	int	size;

	if (is_sorted(data->stack[A]))
		return ;
	size = data->size[A];
	if (data->size[A] < 250)
		chunk_div = 4;
	else
		chunk_div = 8;
	i = 1;
	while (!is_sorted(data->stack[A]))
	{
		while (data->size[B] < (size * i / chunk_div) - ((i - 1) * size / chunk_div))
		{
			first = first_move(data, (i - 1) * size / chunk_div, i * size / chunk_div);
			to_pos(data, -get_pivot_pos(data, first->frame, A), list, A);
			push(data, A, B, list);
		}
		to_pos(data, -((i - 1) * size / chunk_div) - get_pivot_pos(data, data->small[A], A), list, A);
		while (data->stack[B])
		{
			to_pos(data, -get_pivot_pos(data, data->big[B], B), list, B);
			push(data, B, A, list);
		}
		to_pos(data, -((size * i / chunk_div) - ((i - 1) * size / chunk_div)), list, A);
		i++;
	}
}

