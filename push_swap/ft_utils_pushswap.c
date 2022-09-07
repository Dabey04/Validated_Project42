/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pushswap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:47:29 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 22:49:13 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

int	ft_isdoubl(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_not_digit(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_is_not_int(char *argv[])
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	a_is_sorted(t_stack *a)
{
	t_node	*p_a1;
	t_node	*p_a2;

	p_a1 = a->top;
	p_a2 = a->top->next;
	while (p_a2 != NULL)
	{
		if (p_a1->n > p_a2->n)
			return (0);
		p_a1 = p_a1->next;
		p_a2 = p_a2->next;
	}
	return (1);
}
