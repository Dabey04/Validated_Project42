/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:58:03 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 23:44:59 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	write(1, "rrr\n", 4);
}

void	ft_sort_two(t_stack **stack, char a_b)
{
	if ((*stack)->top->n > (*stack)->top->next->n)
	{
		if (a_b == 'a')
			ft_sa(stack, 0);
		else
			ft_sb(stack, 0);
	}
}

void	ft_sort_three(t_stack **a)
{
	if ((*a)->top->n > (*a)->top->next->n)
	{
		if ((*a)->top->n < (*a)->top->next->next->n)
			ft_sa(a, 0);
		else if ((*a)->top->next->n > (*a)->top->next->next->n)
		{
			ft_sa(a, 0);
			ft_rra(a, 0);
		}
		else
			ft_ra(a, 0);
	}
	else if ((*a)->top->n < (*a)->top->next->next->n)
	{
		if ((*a)->top->next->n > (*a)->top->next->next->n)
		{
			ft_sa(a, 0);
			ft_ra(a, 0);
		}
	}
	else
		ft_rra(a, 0);
}

void	ft_sort_four(t_stack **a, t_stack **b)
{
	ft_pb(a, b);
	ft_sort_three(a);
	if ((*b)->top->n < (*a)->top->n)
		ft_pa(a, b);
	else if ((*b)->top->n > (*a)->top->n && (*b)->top->n < (*a)->top->next->n)
	{
		ft_pa(a, b);
		ft_sa(a, 0);
	}
	else if ((*b)->top->n > (*a)->top->next->n
		&& (*b)->top->n < (*a)->top->next->next->n)
	{
		ft_rra(a, 0);
		ft_pa(a, b);
		ft_ra(a, 0);
		ft_ra(a, 0);
	}
	else
	{
		ft_pa(a, b);
		ft_ra(a, 0);
	}
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	push_min_2b(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
	ft_pa(a, b);
}
