/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:50:18 by julboyer          #+#    #+#             */
/*   Updated: 2021/11/24 14:39:05 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_error(t_stack **stack)
{
	write (2, "Error\n", 6);
	psw_delstack(*stack);
	return (-1);
}

int	parse(int ac, char **av, t_stack **stack)
{
	int i;
	i = 1;
	while (i < ac)
	{
		if (checkargs(av[i], stack))
			return (parse_error(stack));
	}
	return (0);
}
