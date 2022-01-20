/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 17:53:17 by dabey             #+#    #+#             */
/*   Updated: 2021/09/23 19:29:33 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(va_list *my_list, int *nb_print)
{
	char	*str;
	int		count;

	str = va_arg(*my_list, char *);
	count = ft_strlen(str);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		(*nb_print) += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		(*nb_print) += count;
	}
}
