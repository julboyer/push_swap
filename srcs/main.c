/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:09:43 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/02 17:44:53 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		last_set;
	int		stck;
	int		i;

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

int	init_stack(t_data *data, int ac, char **av)
{
	int		i;
	int		ret;
	char	**ret_split;

	i = 1;
	data->stack[A] = NULL;
	data->stack[B] = NULL;
	while (i < ac)
		ret = checkargs(av[i++], &data->stack[0], &ret_split);
	if (ret == -1)
	{
		split_free(ret_split);
		write(2, "Error\n", ft_strlen("Error\n"));
		return (-1);
	}
	data->size[0] = ft_pswsize(data->stack[0]);
	data->size[1] = 0;
	data->big[0] = ft_pswbig(data->stack[0]);
	data->small[0] = ft_pswsmall(data->stack[0]);
	data->med[0] = data->size[0] / 2;
	set_index(data);
	return (0);
}

void	print_inst(t_instructions **list)
{
	t_instructions	*tmp;

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

int	main(int ac, char **av)
{
	t_data			data;
	t_instructions	*list;

	if (ac > 1)
	{
		list = NULL;
		if (!init_stack(&data, ac, av) && data.size[A] > 1)
		{
			if (data.size[A] <= 20)
				small_sort(&data, &list);
			else
				order_start(&data, &list);
			if (list)
				print_inst(&list);
		}
		psw_delstack(data.stack[A]);
	}
}
