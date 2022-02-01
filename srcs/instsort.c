/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:42:04 by julboyer          #+#    #+#             */
/*   Updated: 2022/01/30 14:16:06 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	replace_and_del_first(t_instructions *lista, t_instructions **listb,
	char *search, char *replace)
{
	t_instructions *tpmb;

	while (lista && ft_strcmp(search, lista->inst))
		lista = lista->next;
	if (lista)
	{
		lista->inst = ft_strcpy(lista->inst, replace);
		lista = *listb;
		tpmb = lista->next;
		free(lista->inst);
		free(lista);
		*listb = tpmb;
	}
}

static void	del_next(t_instructions *list)
{
	t_instructions *tmp;

	tmp = list->next->next->next;
	free(list->next->next->inst);
	free(list->next->next);
	free(list->next->inst);
	free(list->next);
	list->next = tmp;
}

int	useless_inst_check_a(t_instructions *list)
{
	t_instructions *tmp;
	int				ret;

	ret = 0;
	while (list && list->next && list->next->next)
	{
		while (!strcmp("sa", list->next->inst) && !strcmp("sa", list->next->next->inst))
		{
			tmp = list->next->next->next;
			del_next(list);
			list = tmp;
			ret = 1;
		}
		if (!strcmp("ra", list->next->inst) && !strcmp("rra", list->next->next->inst))
		{
			del_next(list);
			ret = 1;
		}
		else if (!strcmp("rra", list->next->inst) && !strcmp("ra", list->next->next->inst))
		{
			del_next(list);
			ret = 1;
		}
		list = list->next;
	}
	return (ret);
}

int	useless_inst_check_b(t_instructions *list)
{
	t_instructions *tmp;
	int				ret;

	ret = 0;
	while (list && list->next && list->next->next)
	{
		while (!strcmp("sb", list->next->inst) && !strcmp("sb", list->next->next->inst))
		{
			tmp = list->next->next->next;
			del_next(list);
			list = tmp;
			ret = 1;
		}
		if (!strcmp("rb", list->next->inst) && !strcmp("rrb", list->next->next->inst))
		{
			del_next(list);
			ret = 1;
		}
		else if (!strcmp("rrb", list->next->inst) && !strcmp("rb", list->next->next->inst))
		{
			del_next(list);
			ret = 1;
		}
		list = list->next;
	}
	return (ret);
}

void	print_inst2(t_instructions **list)
{
	t_instructions *tmp;

	tmp = *list;
	while (tmp)
	{
		write(1, "#", 1);
		write(1, tmp->inst, ft_strlen(tmp->inst));
		write(1, "\n", 1);
		tmp = tmp->next;
	}
//	inst_delstack(*list);
//	*list = NULL;
}

void	ft_instmerge(t_instructions *list[2], int skip)
{
	t_instructions *tmpa;
	t_instructions *tmpb;
	int i;
	int ret;

	tmpa = list[A];
	tmpb = list[B];

	if (tmpa)
	{
		ret = 1;
		while (ret == 1)
		{
			ret = useless_inst_check_a(list[A]);
		}
	}
	if (tmpb)
	{
		ret = 1;
		while (ret == 1)
		{
			ret = useless_inst_check_b(list[B]);
		}
	}
	if (tmpa && tmpb)
	{
		i = 0;
		while (i++ < skip && tmpa->next)
			tmpa = tmpa->next;
		while (ft_strcmp("pa", tmpb->inst) && tmpa->next)
		{
			if (!ft_strcmp("sb", tmpb->inst))
				replace_and_del_first(tmpa, &tmpb, "sa", "ss");
			else if (!ft_strcmp("rb", tmpb->inst))
				replace_and_del_first(tmpa, &tmpb, "ra", "rr");
			else if (!ft_strcmp("rrb", tmpb->inst))
				replace_and_del_first(tmpa, &tmpb, "rra", "rrr");
			tmpa = tmpa->next;
		}
		while (tmpa->next)
			tmpa = tmpa->next;
		tmpa->next = tmpb;
		list[B] = NULL;
	}
}
