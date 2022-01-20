/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:05:49 by dabey             #+#    #+#             */
/*   Updated: 2021/09/23 20:03:39 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_di(int number)
{
	int	len;

	len = 1;
	if (number == -2147483648)
		return (10);
	if (number < 0)
		number *= -1;
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int	ft_length_u(unsigned int number)
{
	int	len;

	len = 1;
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	return (len);
}

int	ft_length_x(long number)
{
	int	len;

	len = 1;
	while (number >= 16)
	{
		number /= 16;
		len++;
	}
	return (len);
}
