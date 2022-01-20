/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exaupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:42:33 by dabey             #+#    #+#             */
/*   Updated: 2021/09/17 17:22:11 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_exaupper(va_list *my_list, int *nb_print)
{
	unsigned int	exa_up;
	int				count;

	exa_up = va_arg(*my_list, unsigned int);
	count = ft_length_x(exa_up);
	ft_putnbr_base(exa_up, "0123456789ABCDEF");
	(*nb_print) += count;
}
