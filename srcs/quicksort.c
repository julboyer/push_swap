/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:26:51 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/01 02:11:43 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack *first_move(t_data *data, int chunk_max)
{
	t_stack *ret;

	ret = data->stack[A];
	while (ret->index >= chunk_max)
		ret = ret->next;
	return (ret);
}

t_stack *last_move(t_data *data, int chunk_max)
{
	t_stack *ret;
	t_stack *tmp;

	ret = data->stack[A];
	while (ret)
	{
		if (ret->index < chunk_max)
			tmp = ret;
		ret = ret->next;
	}
	return (tmp);
}

void	order_start(t_data *data, t_list **list_a, t_list **list_b)
{
	int chunk_div;
	t_stack *first;
	t_stack *last;
	int i;

	if (data->size[A] < 250)
		chunk_div = 5;
	else
		chunk_div =11;
	i = 1;
	while (data->stack[A])
	{
		first = first_move(data, i * data->size[A] / chunk_div);
		last = last_move(data, i * data->size[A] / chunk_div);
		if (get_pivot_pos(data, first->frame, A) < data->size[A] - get_pivot_pos(data, last->frame, A))
		{
			to_top(data, first, list_a, A);
			push(data, A, B, list_a);
		}
		i++;
	}
	
}

/*
98 99 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 65 64 63 62 61 60 59 58 57 56 55 54 53 52 32 51 50 49 48 47 14 46 45 43 42 41 40 39 38 37 36 35 34 33 31 30 29 28 27 26 25 24 23 22 21 7 20 19 18 17 16 15 13 12 11 10 9 8 6 5 4 3 2 100 
1 

1 2 3 

*/