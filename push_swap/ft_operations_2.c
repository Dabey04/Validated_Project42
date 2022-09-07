/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:05:07 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 17:07:20 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, int rr)
{
	t_node	*tmp;

	tmp = (*a)->top;
	(*a)->top = (*a)->top->next;
	tmp->next = NULL;
	tmp->prev = (*a)->end;
	(*a)->end->next = tmp;
	(*a)->end = (*a)->end->next;
	if (!rr)
		write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b, int rr)
{
	t_node	*tmp;

	tmp = (*b)->top;
	(*b)->top = (*b)->top->next;
	tmp->next = NULL;
	tmp->prev = (*b)->end;
	(*b)->end->next = tmp;
	(*b)->end = (*b)->end->next;
	if (!rr)
		write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	write(1, "rr\n", 3);
}

void	ft_rra(t_stack **a, int rrr)
{
	t_node	*tmp;

	tmp = (*a)->end;
	(*a)->end = (*a)->end->prev;
	(*a)->end->next = NULL;
	tmp->prev = NULL;
	tmp->next = (*a)->top;
	(*a)->top->prev = tmp;
	(*a)->top = tmp;
	if (!rrr)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int rrr)
{
	t_node	*tmp;

	tmp = (*b)->end;
	(*b)->end = (*b)->end->prev;
	(*b)->end->next = NULL;
	tmp->prev = NULL;
	tmp->next = (*b)->top;
	(*b)->top->prev = tmp;
	(*b)->top = tmp;
	if (!rrr)
		write(1, "rrb\n", 4);
}
