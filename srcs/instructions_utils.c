/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:19:48 by julboyer          #+#    #+#             */
/*   Updated: 2021/12/27 17:15:12 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*ft_instlast(t_instructions *lst)
{
	t_instructions	*res;

	if (!lst)
		return (NULL);
	res = lst;
	while (res->next)
		res = res->next;
	return (res);
}

void	ft_instadd_back(t_instructions **alst, t_instructions *new)
{
	t_instructions	*res;

	res = ft_instlast(*alst);
	if (!res)
		*alst = new;
	else
		res->next = new;
}

t_instructions	*ft_instnew(char *inst)
{
	t_instructions	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->inst = inst;
	new->next = NULL;
	return (new);
}

void	inst_delstack(t_instructions *stack)
{
	t_instructions *tmp;
	while (stack->next)
	{
		tmp = stack->next;
		free(stack->inst);
		free (stack);
		stack = tmp;
	}
	free(stack->inst);
	free (stack);
}
