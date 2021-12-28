/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:09:43 by julboyer          #+#    #+#             */
/*   Updated: 2021/12/27 17:51:26 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_data *data, int ac, char **av)
{
	int i;

	i = 1;
	data->stack[A] = NULL;
	data->stack[B] = NULL;
	while (i < ac)
		checkargs(av[i++], &data->stack[0]);
	data->size[0] = ft_pswsize(data->stack[0]);
	data->size[1] = 0;
	data->big[0] = ft_pswbig(data->stack[0]);
	data->small[0] = ft_pswsmall(data->stack[0]);
	data->med[0] = data->size[0] / 2;
}

void	print_inst(t_instructions **list)
{
	t_instructions *tmp;

	tmp = *list;
	while (tmp)
	{
		write(1, tmp->inst, ft_strlen(tmp->inst));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	inst_delstack(*list);
	*list = NULL;
}

int main(int ac, char **av)
{
	t_data data;
	t_instructions *list[2];

	if (ac > 1)
	{
		list[A] = NULL;
		list[B] = NULL;
		init_stack(&data, ac, av);
		if (data.size[A] > 1)
		{
			quicksort_start(&data, &list[A], &list[B]);
//			if (list[A] || list [B])
//			{
				ft_instmerge(list, data.skip);
				print_inst(&list[A]);
//			}
			psw_delstack(data.stack[A]);
		}
	}
}
