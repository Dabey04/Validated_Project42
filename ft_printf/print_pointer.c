/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:17:30 by dabey             #+#    #+#             */
/*   Updated: 2021/09/23 19:49:02 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_usual(long ptr)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(ptr, "0123456789abcdef");
}

void	print_pointer(va_list *my_list, int *nb_print)
{
	long	ptr;
	int		count;

	ptr = va_arg(*my_list, long);
	count = ft_length_x(ptr) + 2;
	if (ptr == -1)
	{
		ft_putstr_fd("0xffffffffffffffff", 1);
		(*nb_print) += 18;
	}
	else if (ptr == LONG_MIN)
	{
		ft_putstr_fd("0x8000000000000000", 1);
		(*nb_print) += 18;
	}
	else
	{
		ft_usual(ptr);
		(*nb_print) += count;
	}
}
