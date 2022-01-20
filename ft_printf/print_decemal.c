/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decemal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 19:18:18 by dabey             #+#    #+#             */
/*   Updated: 2021/09/23 20:00:15 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_decemal(va_list *my_list, int *nb_print)
{
	int	number;
	int	count;

	number = va_arg(*my_list, int);
	count = ft_length_di(number);
	if (number < 0)
	{
		ft_putchar_fd('-', 1);
		number = -number;
		count++;
	}
	if (count > 0)
		ft_putnbr(number, 1);
	(*nb_print) += count;
}
