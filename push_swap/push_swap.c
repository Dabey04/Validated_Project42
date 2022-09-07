/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:41:40 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 23:23:28 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_stack **s, int len)
{
	*s = malloc(sizeof(t_stack));
	if (!s)
		return ;
	(*s)->top = NULL;
	(*s)->end = NULL;
	(*s)->len = len;
	(*s)->nb_ra = 0;
	(*s)->nb_rra = 0;
}

int	ft_check_error(char *argv[], int argc)
{
	if (ft_isdoubl(argv))
		return (1);
	else
		if (ft_not_digit(argv, argc))
			return (1);
	else
		if (ft_is_not_int(argv))
			return (1);
	return (0);
}

void	ft_creat_stack(t_stack **a, char *argv[], int argc, int *tab)
{
	int	i;
	int	nb_atoi;

	i = 0;
	while (i < argc)
	{
		nb_atoi = ft_atoi(argv[i]);
		tab [i] = nb_atoi;
		ft_add_back(a, nb_atoi);
		i++;
	}
}

void	push_swap(t_stack **a, int *tab)
{
	t_stack	*b;

	ft_init(&b, 0);
	if ((*a)->len == 2)
		ft_sort_two(a, 'a');
	else if ((*a)->len == 3)
		ft_sort_three(a);
	else if ((*a)->len == 4)
		ft_sort_four(a, &b);
	else if ((*a)->len == 5)
		ft_sort_five(a, &b);
	else if ((*a)->len > 5)
		ft_big_sort(a, &b, tab);
	ft_stack_clear(&b);
}

int	main(int argc, char *argv[])
{
	int		*tab;
	int		i;
	t_stack	*a;

	i = 0;
	a = NULL;
	if (argc == 1)
		return (0);
	if (ft_check_error(argv + 1, argc - 1))
	{
		ft_error();
		return (EXIT_FAILURE);
	}
	ft_init(&a, argc - 1);
	tab = malloc((argc - 1) * sizeof(int));
	if (!tab)
		return (1);
	ft_creat_stack(&a, argv + 1, argc - 1, tab);
	i = a_is_sorted(a);
	if (i == 0)
		push_swap(&a, tab);
	ft_stack_clear(&a);
	free(tab);
	return (EXIT_SUCCESS);
}
