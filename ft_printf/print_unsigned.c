/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lydiabey <lydiabey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 15:13:58 by dabey             #+#    #+#             */
/*   Updated: 2021/12/06 13:17:56 by lydiabey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_length_u(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

void	print_unsigned(va_list *my_list, int *nb_print)
{
	unsigned int	n;
	char			*num;
	int				count;

	count = 0;
	n = va_arg(*my_list, unsigned int);
	if (n == 0)
		count += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		count += ft_printstr(num);
		free(num);
	}
	(*nb_print) += count;
}
