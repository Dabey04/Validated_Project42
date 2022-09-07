/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:10:00 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 23:45:18 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quicksort(int *a, int first, int last)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (a[i] <= a[pivot] && i < last)
				i++;
			while (a[j] > a[pivot])
				j--;
			if (i < j)
				swap(&a[i], &a[j]);
		}
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		quicksort(a, first, j - 1);
		quicksort(a, j + 1, last);
	}
}

void	ft_full_case(t_stack **a, int *tab)
{
	int		i;
	int		j;
	t_node	*tmp;

	i = 0;
	tmp = (*a)->top;
	while (i < (*a)->len)
	{
		j = 0;
		while (tmp->n != tab[j])
			j++;
		tmp->num = j;
		tmp = tmp->next;
		i++;
	}
}

void	ft_radix_sort(t_stack **a, t_stack **b, int len, int i)
{
	int	j;
	int	k;
	int	mb;

	mb = 0;
	while (((len) >> mb) != 0)
		++mb;
	while (i < mb)
	{
		if (a_is_sorted(*a))
			return ;
		j = 0;
		while (j < len)
		{
			k = (*a)->top->num;
			if (((k >> i) & 1) == 0)
				ft_pb(a, b);
			else
				ft_ra(a, 0);
			j++;
		}
		i++;
		while ((*b)->top)
			ft_pa(a, b);
	}
}

void	ft_big_sort(t_stack **a, t_stack **b, int *tab)
{
	int	i;

	i = 0;
	quicksort(tab, 0, (*a)->len - 1);
	ft_full_case(a, tab);
	ft_radix_sort(a, b, (*a)->len, i);
}
