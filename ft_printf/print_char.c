/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:23:22 by dabey             #+#    #+#             */
/*   Updated: 2021/09/23 17:28:36 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list *my_list, int *nb_print)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*my_list, int);
	ft_putchar_fd(c, 1);
	(*nb_print)++;
}
