/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:32:41 by julboyer          #+#    #+#             */
/*   Updated: 2022/02/01 17:53:52 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A 0
# define B 1

# include "libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_stack
{
	long int	frame;
	int			index;
	struct s_stack		*next;
}				t_stack;

typedef struct	s_data
{
	t_stack *stack[2];
	int	size[2];
	int	med[2];
	int	small[2];
	int	big[2];
	int skip;
}				t_data;

typedef struct	s_instructions
{
	char			*inst;
	struct s_instructions	*next;
}				t_instructions;

void			ft_reverse_rotate(t_stack **stack, t_instructions **list,
					char index);
void			ft_rotate(t_stack **stack, t_instructions **list, char index);
void			push(t_data *data, int indexf, int indext,
					t_instructions **list);
void			swap(t_stack **stack, t_instructions **list, char index);
void			psw_delstack(t_stack *stack);
t_stack			*ft_pswnew(int frame);
void			ft_pswadd_front(t_stack **alst, t_stack *new);
int				checkargs(const char *s, t_stack **stack);
long int		ft_atol(const char *str);
void			ft_pswadd_back(t_stack **alst, t_stack *new);
int				ft_pswsize(t_stack *lst);
int				ft_pswbig(t_stack *stack);
int				ft_pswsmall(t_stack *stack);
int				is_sorted(t_stack *stack);
int				is_reverse_sorted(t_stack *stack);
t_stack			*ft_pswlast(t_stack *lst);
int				ft_strcmp(char *s1, char *s2);
void			ft_instadd_back(t_instructions **alst, t_instructions *new);
t_instructions	*ft_instnew(char *inst);
int				to_top(t_data *data, t_stack *current, t_instructions **list,
					int stack_index);
int				to_second(t_data *data, t_stack *current, t_instructions **list,
					int stack_index);
void			swap_rotate(t_data *data, t_instructions **list, int index);
void			swap_rrotate(t_data *data, t_instructions **list, int index);
int				get_pivot_pos(t_data *data, int pivot, int	index);
void			order_start(t_data *data, t_instructions **list);
int				partition_a(t_data *data, t_instructions **list, int start,
					int end);
int				partition_b(t_data *data, t_instructions **list, int start,
					int end);
void			ft_instmerge(t_instructions *list[2], int skip);
void			inst_delstack(t_instructions *stack);
int				ft_abs(int val);
int				to_pos(t_data *data, int move, t_instructions **list, int stack_index);
void 			print_stack(t_data *data, int index);
int				get_index_pos(t_data *data, int index, int stack);


void	print_inst2(t_instructions **list);

#endif
