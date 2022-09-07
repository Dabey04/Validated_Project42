/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:42:08 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 23:48:09 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_length_d(int number)
{
	int	len;

	len = 1;
	if (number == -2147483648)
		return (10);
	if (number < 0)
		number *= -1;
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

t_node	*ft_node_new(int nb)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->n = nb;
	new->num = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_add_back(t_stack **a, int nb)
{
	t_stack	*p_a;
	t_node	*new;

	new = ft_node_new(nb);
	p_a = *a;
	if (p_a->top == NULL)
	{
		p_a->top = new;
		p_a->end = new;
	}
	else
	{
		new->prev = p_a->end;
		p_a->end->next = new;
		p_a->end = p_a->end->next;
	}
}

void	ft_stack_clear(t_stack **a)
{
	t_stack	*p_a;
	t_node	*next_elem;

	p_a = NULL;
	next_elem = NULL;
	if (a == NULL)
		return ;
	p_a = *a;
	while (p_a->top)
	{
		next_elem = p_a->top->next;
		free(p_a->top);
		p_a->top = next_elem;
	}
	free(*a);
}
