/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:56:29 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 22:36:21 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa_func(t_stack **b)
{
	if ((*b)->top->next == NULL)
	{
		(*b)->top = NULL;
		(*b)->end = NULL;
	}
	else
	{
		(*b)->top = (*b)->top->next;
		(*b)->top->prev = NULL;
	}
}

void	ft_pb_func(t_stack **a)
{
	if ((*a)->top->next == NULL)
	{
		(*a)->top = NULL;
		(*a)->end = NULL;
	}
	else
	{
		(*a)->top = (*a)->top->next;
		(*a)->top->prev = NULL;
	}
}

void	ft_find_min(t_node **tmp, int *min, int *i, int *j)
{
	while (*tmp != NULL)
	{
		if ((*tmp)->n < *min)
		{
			*min = (*tmp)->n;
			*i = *j;
		}
		(*j)++;
		(*tmp) = (*tmp)->next;
	}
}

void	ft_ra_or_rra(t_stack **a, t_stack **b, int *i)
{
	if (*i <= ((*a)->len / 2))
	{
		while (*i > 0)
		{
			ft_ra(a, 0);
			(*i)--;
		}
		ft_pb(a, b);
	}
	else
	{
		while (((*a)->len - *i) > 0)
		{
			ft_rra(a, 0);
			(*i)++;
		}
		ft_pb(a, b);
	}
}
