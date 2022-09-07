/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:58:39 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 17:32:22 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int ss)
{
	int	tmp;

	tmp = (*a)->top->next->n;
	(*a)->top->next->n = (*a)->top->n;
	(*a)->top->n = tmp;
	if (!ss)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b, int ss)
{
	int	tmp;

	tmp = (*b)->top->next->n;
	(*b)->top->next->n = (*b)->top->n;
	(*b)->top->n = tmp;
	if (!ss)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, 1);
	ft_sb(b, 1);
	write(1, "ss\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	if (b)
	{
		tmp = (*b)->top;
		ft_pa_func(b);
		if ((*a)->top != NULL)
		{
			tmp->next = (*a)->top;
			(*a)->top->prev = tmp;
		}
		else
		{
			tmp->next = NULL;
			tmp->prev = NULL;
			(*a)->end = tmp;
		}
		(*a)->top = tmp;
		(*a)->len += 1;
		(*b)->len -= 1;
		write(1, "pa\n", 3);
	}
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	if (a)
	{
		tmp = (*a)->top;
		ft_pb_func(a);
		if ((*b)->top != NULL)
		{
			tmp->next = (*b)->top;
			tmp->prev = NULL;
			(*b)->top->prev = tmp;
		}
		else
		{
			tmp->next = NULL;
			tmp->prev = NULL;
			(*b)->end = tmp;
		}
		(*b)->top = tmp;
		(*b)->len += 1;
		(*a)->len -= 1;
		write(1, "pb\n", 3);
	}
}
