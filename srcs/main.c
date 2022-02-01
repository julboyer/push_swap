/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:09:43 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/01 14:53:41 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_data *data, int index)
{
	t_stack *tmp;

	tmp = data->stack[index];
	while (tmp)
	{
		printf("|%d|", tmp->index);
		tmp = tmp->next;
	}
	printf("\n");
}

void	set_index(t_data *data)
{
	t_stack *tmp;
	t_stack *tmp2;
	int last_set;
	int stck;
	int i;

	last_set = data->small[A];
	i = 1;
	while (last_set != data->big[A])
	{
		tmp = data->stack[A];
		stck = data->big[A];
		while (tmp)
		{
			if (tmp->frame <= stck && tmp->frame > last_set)
			{
				tmp2 = tmp;
				stck = tmp->frame;
			}
			tmp = tmp->next;
		}
		tmp2->index = i;
		last_set = tmp2->frame;
		i++;
	}
	
}

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
	data->skip = 0;
	set_index(data);
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
	t_instructions *list;

	if (ac > 1)
	{
		list = NULL;
		init_stack(&data, ac, av);
//		print_stack(&data, A);
		if (data.size[A] > 1)
		{
			order_start(&data, &list);
/*			if (is_sorted(data.stack[A]) && !data.stack[B])
				printf("OK ");
			print_stack(&data, A);
			printf("skip %d\n", data.skip);*/
			if (list)
			{			
//				print_inst2(&list[B]);
//				ft_instmerge(list, data.skip);
				print_inst(&list);
			}
			psw_delstack(data.stack[A]);
		}
	}
}
