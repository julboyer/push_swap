/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:02:58 by julboyer          #+#    #+#             */
/*   Updated: 2021/12/28 14:22:25 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_a2(t_data *data, t_stack **tmp_start, t_instructions **list,
	int i)
{
	t_stack *move;
	t_stack *tmp;
	t_stack *pivot;

	tmp = *tmp_start;
	move = tmp;
	tmp = tmp->next;
	pivot = data->stack[A];
	if (move->frame < pivot->frame)
	{
		if (i > data->med[A])
		{
			to_top(data, move, list, A);
			while (move->next->frame > pivot->frame)
				swap_rotate(data, list, A);
		}
		else
		{
			to_second(data, move, list, A);
			while (move->next->frame > pivot->frame)
				swap_rrotate(data, list, A);
		}
	}
}

int	partition_a(t_data *data, t_instructions **list, t_stack *pivot,
	int lenght)
{
	t_stack *tmp;
	int i;

	i = -1;
	tmp = pivot;
	while (++i < lenght)
	{
		partition_a2(data, &tmp, list, i);
		tmp = tmp->next;
	}
	return (get_pivot_pos(data, pivot->frame, A));
}

void	partition_b2(t_data *data, t_stack **tmp_start, t_instructions **list,
	int i)
{
	t_stack *move;
	t_stack *pivot;

	move = *tmp_start;
	pivot = data->stack[B];
//	printf(" part b2 %p, %p\n", move, pivot);
	if (move->frame > pivot->frame)
	{
		if (i > data->med[B])
		{
			to_top(data, move, list, B);
			while (move->next->frame < pivot->frame)
				swap_rotate(data, list, B);
		}
		else
		{
			to_second(data, move, list, B);
			while (move->next->frame < pivot->frame)
				swap_rrotate(data, list, B);
		}
	}
}

int	partition_b(t_data *data, t_instructions **list, t_stack *pivot,
	int lenght)
{
	t_stack *tmp;
	int i;

	i = -1;
	tmp = pivot->next;
//	printf("part b %p, %p\n", pivot, pivot->next);
	while (++i < lenght && tmp->next)
	{
		partition_b2(data, &tmp, list, i);
		tmp = tmp->next;
	}
	return (get_pivot_pos(data, pivot->frame, B));
}