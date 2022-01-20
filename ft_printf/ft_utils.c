/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:42:46 by dabey             #+#    #+#             */
/*   Updated: 2021/09/23 19:51:23 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
}

void	ft_putstr_len(char *s, int count)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0' && i < count)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_putnbr_base(long n, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar_fd(base[n % base_len], 1);
	return (1);
}
