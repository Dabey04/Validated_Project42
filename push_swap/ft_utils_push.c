/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:41:21 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 23:41:19 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_2b(t_stack **a, t_stack **b)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		min;
	int		z;

	z = 0;
	while (z++ < 2)
	{	
		i = 0;
		j = 1;
		tmp = (*a)->top->next;
		min = (*a)->top->n;
		ft_find_min(&tmp, &min, &i, &j);
		ft_ra_or_rra(a, b, &i);
	}
}

int	ft_nb_coup(t_stack *a)
{
	int	i;
	int	num;
	int	nb_coup;

	i = 0;
	num = 0;
	nb_coup = 0;
	while (i < a->len)
	{
		num = a->top->num;
		if (((num >> i) & 1) == 1)
		{
			a->top = a->top->next;
			nb_coup++;
		}
		else if (((num >> i) & 1) == 0)
			return (a->len - nb_coup);
	}
	return (i);
}
