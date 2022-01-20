/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:01:00 by dabey             #+#    #+#             */
/*   Updated: 2021/09/23 19:53:27 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_find(char format_i, char *type)
{
	int	i;

	i = 0;
	while (type[i])
	{
		if (type[i] == format_i)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_pars(const char format, va_list *my_list, int *nb_print,
void (*function_tab[9])(va_list*, int*))
{
	int		index;

	index = ft_find(format, TYPE_PRINT);
	if (index != -1)
	{
		function_tab[index](my_list, nb_print);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			nb_print;
	va_list		my_list;
	void		(*function_tab[9])(va_list*, int*);

	i = 0;
	nb_print = 0;
	ft_remp_tabfunc(function_tab);
	va_start(my_list, format);
	while (format[i] != '\0')
	{
		while (format[i] != '\0' && format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			nb_print++;
			i++;
		}
		if (format[i] == '%')
		{
			i += ft_pars(format[i + 1], &my_list, &nb_print, function_tab);
			i++;
		}
	}
	va_end(my_list);
	return (nb_print);
}

void	ft_remp_tabfunc(void (*function_tab[9])(va_list*, int *))
{
	function_tab[0] = print_decemal;
	function_tab[1] = print_decemal;
	function_tab[2] = print_char;
	function_tab[3] = print_string;
	function_tab[4] = print_pointer;
	function_tab[5] = print_exalower;
	function_tab[6] = print_exaupper;
	function_tab[7] = print_unsigned;
	function_tab[8] = print_percent;
}
