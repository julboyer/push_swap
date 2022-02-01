/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:19:48 by julboyer          #+#    #+#             */
/*   Updated: 2022/01/31 15:14:57 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pswadd_front(t_stack **alst, t_stack *new)
{
	new->next = *alst;
	*alst = new;
}

t_stack	*ft_pswlast(t_stack *lst)
{
	t_stack	*res;

	if (!lst)
		return (NULL);
	res = lst;
	while (res->next)
	{
		res = res->next;
	}
	return (res);
}

void	ft_pswadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*res;

	res = ft_pswlast(*alst);
	if (!res)
		*alst = new;
	else
		res->next = new;
}

t_stack	*ft_pswnew(int frame)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->frame = frame;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	psw_delstack(t_stack *stack)
{
	t_stack *tmp;
	while (stack->next)
	{
		tmp = stack->next;
		free (stack);
		stack = tmp;
	}
	free (stack);
}