/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exalower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:21:00 by dabey             #+#    #+#             */
/*   Updated: 2021/09/17 17:21:48 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_exalower(va_list *my_list, int *nb_print)
{
	unsigned int	exa_low;
	int				count;

	exa_low = va_arg(*my_list, unsigned int);
	count = ft_length_x(exa_low);
	ft_putnbr_base(exa_low, "0123456789abcdef");
	(*nb_print) += count;
}
