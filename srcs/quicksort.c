/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:26:51 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/01 18:08:40 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *first_move(t_data *data, int chunk_min, int chunk_max)
{
	t_stack *ret;

	ret = data->stack[A];
//	printf("chunk %d, %d\n", chunk_min, chunk_max);
	while (ret && (ret->index >= chunk_max || ret->index < chunk_min))
	{
//		printf("ret first %d, chunk%d\n", ret->index, chunk_max);
		ret = ret->next;
	}
	return (ret);
}

t_stack *last_move(t_data *data, int chunk_min, int chunk_max)
{
	t_stack *ret;
	t_stack *tmp;

	ret = data->stack[A];
	while (ret)
	{
//		printf("ret %d\n", ret->index);
		if (ret->index < chunk_max && ret->index >= chunk_min)
			tmp = ret;
		ret = ret->next;
	}
	return (tmp);
}


void	push_check(t_data *data, t_instructions **list)
{
	t_stack *tmp;
//	t_stack *stck;
	int		cmp;

	if (data-> stack[B] && data->stack[A]->frame < data->small[B])
		to_pos(data, -get_pivot_pos(data, data->big[B], B), list, B);
	else if (data-> stack[B])
	{
		tmp = data->stack[B];
		cmp = data->small[B];
//		stck = tmp;
		while (tmp)
		{
			if (tmp->frame > cmp && tmp->frame < data->stack[A]->frame)
			{
//				stck = tmp;
				cmp = tmp->frame;
			}
			tmp = tmp->next;
		}
		to_pos(data, -get_pivot_pos(data, cmp, B), list, B);
	}
	push(data, A, B, list);
}

void	order_start(t_data *data, t_instructions **list)
{
	int chunk_div;
	t_stack *first;
	t_stack *last;
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
			printf("first %d\n", first->index);
			last = last_move(data, (i - 1) * size / chunk_div, i * size / chunk_div);
			printf("last %d\n", last->index);
			if (get_pivot_pos(data, first->frame, A) < data->size[A] - get_pivot_pos(data, last->frame, A))
			{
				to_pos(data, -get_pivot_pos(data, first->frame, A), list, A);
				push_check(data, list);
				if (first != last)
				{
					to_pos(data, -get_pivot_pos(data, last->frame, A), list, A);
					push_check(data, list);
				}
			}
			else
			{
				to_pos(data, -get_pivot_pos(data, last->frame, A), list, A);
				push_check(data, list);
				if (first != last)
				{
					to_pos(data, -get_pivot_pos(data, first->frame, A), list, A);
					push_check(data, list);
				}
			}
		}
		print_stack(data, A);
		print_stack(data, B);
		while (data->stack[B])
		{
			to_pos(data, -get_pivot_pos(data, data->big[B], B), list, B);
			push(data, B, A, list);
		}
		to_pos(data, -(data->size[A] / chunk_div), list, A);
		i++;
	}
/*	while (data->stack[A])
	{
		push_check(data, list);
	}*/
}

/*
98 99 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 65 64 63 62 61 60 59 58 57 56 55 54 53 52 32 51 50 49 48 47 14 46 45 43 42 41 40 39 38 37 36 35 34 33 31 30 29 28 27 26 25 24 23 22 21 7 20 19 18 17 16 15 13 12 11 10 9 8 6 5 4 3 2 100 
1 

1 2 3 

*/