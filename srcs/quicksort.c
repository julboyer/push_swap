/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:26:51 by julboyer          #+#    #+#             */
/*   Updated: 2021/12/28 14:32:16 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	quicksort_b(t_data *data, t_instructions **list, int start, int end)
{
	int lenght;
	int pindex;
	t_stack *pivot;

	if (end > start)
	{
		lenght = end - start;
		if (data->stack[B]->frame == data->small[B])
				ft_rotate(&data->stack[B], list, B);
		pivot = data->stack[B];
		printf("%d\n", start);
		pindex = partition_b(data, list, pivot, lenght);
		printf("pindex %d\n", pindex);
		if (pindex - 1 - start > 1 && !is_reverse_sorted(data->stack[B]))
			quicksort_b(data, list, start, pindex - 1);
		if (end - (pindex + 1) > 1 && !is_reverse_sorted(data->stack[B]))
			quicksort_b(data, list, pindex + 1, end);
	}
}

void	quicksort_a(t_data *data, t_instructions **list, int start, int end)
{
	int lenght;
	int pindex;
	t_stack *pivot;

	if (end > start)
	{
		lenght = end - start;
		if (data->stack[A]->frame == data->big[A])
				ft_rotate(&data->stack[A], list, A);
		pivot = data->stack[A];
		pindex = partition_a(data, list, pivot, lenght);
		if (pindex - 1 - start > 1 && !is_sorted(data->stack[A]))
			quicksort_a(data, list, start, pindex - 1);
		if (end - (pindex + 1) > 1 && !is_sorted(data->stack[A]))
			quicksort_a(data, list, pindex + 1, end);
	}
}

void	quicksort_start(t_data *data, t_instructions **list_a,
			t_instructions **list_b)
{
	int pivot;
	t_stack *tmp;
	t_stack *stock;

	if (is_sorted(data->stack[0]))
		return ;
	tmp = data->stack[0];
	pivot = tmp->frame;
	data->skip = 0;
	while (tmp)
	{
		stock = tmp->next;
		if(tmp->frame < pivot)
		{
			data->skip += to_top(data, tmp, list_a, A) + 1;
			if (!is_sorted(data->stack[A]))
				push(data, A, B, list_a);
		}
		tmp = stock;
	}
	if (!is_sorted(data->stack[A]))
		quicksort_a(data, list_a, 0, data->size[A]);
	if (!is_reverse_sorted(data->stack[B]))
		quicksort_b(data, list_b, 0, data->size[B]);
	while (data->stack[B])
		push(data, B, A, list_b);
}

/*
2 1 3 4 
*/