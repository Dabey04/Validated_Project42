/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:41:30 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 23:44:25 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				n;
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*end;
	int				len;
	int				nb_ra;
	int				nb_rra;
}				t_stack;

//**************ft_utils_push_swap**************
void		ft_error(void);
int			ft_isdoubl(char *argv[]);
int			ft_not_digit(char *argv[], int argc);
int			ft_is_not_int(char *argv[]);
int			a_is_sorted(t_stack *a);
//**************ft_utils_2**************
void		ft_pa_func(t_stack **b);
void		ft_pb_func(t_stack **a);
void		ft_ra_or_rra(t_stack **a, t_stack **b, int *i);
//**************ft_utils_push**************
void		push_min_2b(t_stack **a, t_stack **b);
void		ft_find_min(t_node **tmp, int *min, int *i, int *j);
//**************ft_utils_list**************
t_node		*ft_node_new(int nb);
void		ft_stack_clear(t_stack **stack);
void		ft_add_back(t_stack **stack, int nb);
void		ft_full_stack(t_stack **radix, t_stack *a);
//**************ft_sort**************
void		ft_rrr(t_stack **a, t_stack **b);
void		ft_sort_two(t_stack **stack, char a_b);
void		ft_sort_three(t_stack **a);
void		ft_sort_four(t_stack **a, t_stack **b);
void		ft_sort_five(t_stack **a, t_stack **b);
void		ft_big_sort(t_stack **a, t_stack **b, int *tab);
//**************ft_operations_1**************
void		ft_sa(t_stack **a, int ss);
void		ft_sb(t_stack **b, int ss);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **a, t_stack **b);
//**************ft_operations_2**************
void		ft_ra(t_stack **a, int rr);
void		ft_rb(t_stack **b, int rr);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_rra(t_stack **a, int rrr);
void		ft_rrb(t_stack **b, int rrr);
//**************ft_push_swap**************
void		ft_init(t_stack **s, int len);
int			a_is_sorted(t_stack *a);

#endif
