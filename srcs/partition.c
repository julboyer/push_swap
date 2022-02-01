/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:02:58 by julboyer          #+#    #+#             */
/*   Updated: 2022/01/31 01:35:50 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition_a2(t_data *data, int j, t_instructions **list, t_stack **tmp_start, t_stack *pivot)
{
	t_stack *move;

	move = (*tmp_start);
	(*tmp_start) = (*tmp_start)->next;
	if (move->frame < pivot->frame)
	{
		if (get_pivot_pos(data, move->frame, A) < get_pivot_pos(data, pivot->frame, A))
			return (1);
		if (data->size[A] == 2 || (pivot->frame == data->stack[A]->frame && move->frame == data->stack[A]->next->frame))
			swap(&data->stack[A], list, A);
		else if (ft_abs(get_pivot_pos(data, move->frame, A) - get_pivot_pos(data, move->frame, A)) > data->med[A] || pivot->next->frame == move->frame)
		{
			to_second(data, move, list, A);
			while (get_pivot_pos(data, pivot->frame, A) < get_pivot_pos(data, move->frame, A))
			{
				swap_rrotate(data, list, A);
			}
		}
		else
		{
			to_top(data, move, list, A);
			while (get_pivot_pos(data, pivot->frame, A) != j + 1)
			{
				swap_rotate(data, list, A);
			}
		}
		return (1);
	}
	return (0);
}

int	partition_a(t_data *data, t_instructions **list, int start,
	int end)
{
	t_stack *tmp;
	t_stack *pivot;
	int i;
	int j;
	int lenght;

	i = -1;
	pivot = data->stack[A];
	lenght = end - start;
	j = 0;
	tmp = pivot->next;
	if (data->stack[A]->frame == data->big[A])
	{
		ft_rotate(&data->stack[A], list, A);
		return (end);
	}
	while (++i < lenght && tmp)
	{
		if (partition_a2(data, j, list, &tmp, pivot))
			j++;
}
		to_pos(data, start + j - get_pivot_pos(data, pivot->frame, A), list, A);
	return (get_pivot_pos(data, pivot->frame, A));
}

int	partition_b2(t_data *data, int j, t_instructions **list, t_stack **tmp_start, t_stack *pivot)
{
	t_stack *move;

	move = (*tmp_start);
	(*tmp_start) = (*tmp_start)->next;
	if (move->frame > pivot->frame)
	{
		if (get_pivot_pos(data, move->frame, B) < get_pivot_pos(data, pivot->frame, B))
			return (1);
		if (data->size[B] == 2 || (pivot->frame == data->stack[B]->frame && move->frame == data->stack[B]->next->frame))
			swap(&data->stack[B], list, B);
		else if (ft_abs(get_pivot_pos(data, move->frame, B) - get_pivot_pos(data, move->frame, B)) > data->med[B] || pivot->next->frame == move->frame)
		{
			to_second(data, move, list, B);
			while (get_pivot_pos(data, pivot->frame, B) < get_pivot_pos(data, move->frame, B))
			{
				swap_rrotate(data, list, B);
			}
		}
		else
		{
			to_top(data, move, list, B);
			while (get_pivot_pos(data, pivot->frame, B) != j + 1)
			{
				swap_rotate(data, list, B);
			}
		}
		return (1);
	}
	return (0);
}

int	partition_b(t_data *data, t_instructions **list, int start,
	int end)
{
	t_stack *tmp;
	t_stack *pivot;
	int i;
	int j;
	int lenght;

	i = -1;
	pivot = data->stack[B];
	lenght = end - start;
	j = 0;
	tmp = pivot->next;
	if (data->stack[B]->frame == data->small[B])
	{
		ft_rotate(&data->stack[B], list, B);
		return (end);
	}
	while (++i < lenght && tmp)
	{
		if (partition_b2(data, j, list, &tmp, pivot))
			j++;
	}
		to_pos(data, start + j - get_pivot_pos(data, pivot->frame, B), list, B);
	return (get_pivot_pos(data, pivot->frame, B));
}