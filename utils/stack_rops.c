/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:52:54 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/02 02:18:33 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack, t_instructions **list, char index)
{
	t_stack *tmp;

	tmp = *stack;
	if (index == A)
		ft_instadd_back(list, ft_instnew(ft_strdup("rra")));
	else
		ft_instadd_back(list, ft_instnew(ft_strdup("rrb")));
	if (tmp->next)
	{
		while (tmp->next->next)
		{
			tmp = tmp->next;
		}
		tmp->next->next = *stack;
		*stack = tmp->next;
		tmp->next = NULL;
	}
}

void	ft_rotate(t_stack **stack, t_instructions **list, char index)
{
	t_stack *tmp;
	t_stack *tmp2;


	tmp = *stack;
	tmp2 = *stack;
	if (index == A)
		ft_instadd_back(list, ft_instnew(ft_strdup("ra")));
	else
		ft_instadd_back(list, ft_instnew(ft_strdup("rb")));
	if (tmp->next)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = tmp2;
		*stack = tmp2->next;
		tmp = tmp->next;
		tmp->next->next = NULL;
	}
}

void	push(t_data *data, int indexf, int indext, t_instructions **list)
{
	t_stack *tmpf;
	t_stack *tmpt;

	if (indext == A)
		ft_instadd_back(list, ft_instnew(ft_strdup("pa")));
	else
		ft_instadd_back(list, ft_instnew(ft_strdup("pb")));
	tmpf = data->stack[indexf];
	tmpt = data->stack[indext];
	data->stack[indexf] = tmpf->next;
	tmpf->next = tmpt;
	data->stack[indext] = tmpf;
	data->size[indext]++;
	data->size[indexf]--;
	data->med[indext] = data->size[indext] / 2;
	data->med[indexf] = data->size[indexf] / 2;
	data->big[indexf] = ft_pswbig(data->stack[indexf]);
	data->small[indexf] = ft_pswsmall(data->stack[indexf]);
	data->big[indext] = ft_pswbig(data->stack[indext]);
	data->small[indext] = ft_pswsmall(data->stack[indext]);
}

void	swap(t_stack **stack, t_instructions **list, char index)
{
	t_stack	*tmp2;
	t_instructions *inst1;
	t_instructions *inst2;

	if (index == A)
		ft_instadd_back(list, ft_instnew(ft_strdup("sa")));
	else
	{
		inst1 = *list;
		while (inst1)
		{
			if (!ft_strcmp(inst1->inst, "pb"))
				inst2 = inst1;
			inst1 = inst1->next;
		}
		while (inst2 && ft_strcmp("sa", inst2->inst))
			inst2 = inst2->next;
		if (!inst2)
			ft_instadd_back(list, ft_instnew(ft_strdup("sb")));
		else
			ft_strcpy(inst2->inst, "ss");
	}
	tmp2 = (*stack)->next;
	(*stack)->next = tmp2->next;
	tmp2->next = *stack;
	*stack = tmp2;
}