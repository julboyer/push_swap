/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:42:04 by julboyer          #+#    #+#             */
/*   Updated: 2021/12/28 14:36:05 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	replace_and_del_first(t_instructions *lista, t_instructions **listb,
	char *search, char *replace)
{
	t_instructions *tmpa;
	t_instructions *tpmb;

	tmpa = lista;
	while (tmpa->next && ft_strcmp(search, tmpa->inst))
		tmpa = tmpa->next;
	lista->inst = ft_strcpy(lista->inst, replace);
	tmpa = *listb;
	tpmb = tmpa->next;
	free(tmpa->inst);
	free(tmpa);
	*listb = tpmb;
}

static void	del_next(t_instructions *list)
{
	t_instructions *tmp;

	tmp = list->next->next;
	free(list->next->inst);
	free(list->next);
	list->next = tmp;
}

void	useless_inst_check_a(t_instructions *list)
{
	t_instructions *tmp;

	while (list->next)
	{
		while (!strcmp("sa", list->inst) && !strcmp("sa", list->next->inst))
		{
			tmp = list->next->next;
			del_next(list);
			free(list->inst);
			free(list);
			list = tmp;
		}
		if (!strcmp("ra", list->inst) && !strcmp("rra", list->next->inst))
			del_next(list);
		else if (!strcmp("rra", list->inst) && !strcmp("ra", list->next->inst))
			del_next(list);
		list = list->next;
	}
}

void	useless_inst_check_b(t_instructions *list)
{
	t_instructions *tmp;

	while (list->next)
	{
		while (!strcmp("sb", list->inst) && !strcmp("sb", list->next->inst))
		{
			tmp = list->next->next;
			del_next(list);
			free(list->inst);
			free(list);
			list = tmp;
		}
		if (!strcmp("rb", list->inst) && !strcmp("rrb", list->next->inst))
			del_next(list);
		else if (!strcmp("rrb", list->inst) && !strcmp("rb", list->next->inst))
			del_next(list);
		list = list->next;
	}
}

void	ft_instmerge(t_instructions *list[2], int skip)
{
	t_instructions *tmpa;
	t_instructions *tmpb;
	int i;

	tmpa = list[A];
	tmpb = list[B];

	if (tmpa && tmpb)
	{
		i = -1;
		while (++i < skip && tmpa->next)
		{
			tmpa = tmpa->next;
		}
		while (ft_strcmp("pa", tmpb->inst) && tmpa->next)
		{
			if (!ft_strcmp("sb", tmpb->inst))
				replace_and_del_first(tmpa, &tmpb, "sa", "ss");
			if (!ft_strcmp("rb", tmpb->inst))
				replace_and_del_first(tmpa, &tmpb, "ra", "rr");
			if (!ft_strcmp("rrb", tmpb->inst))
				replace_and_del_first(tmpa, &tmpb, "rra", "rrr");
			tmpa = tmpa->next;
		}
		while (tmpa->next)
			tmpa = tmpa->next;
		tmpa->next = tmpb;
		list[B] = NULL;
	}
}
