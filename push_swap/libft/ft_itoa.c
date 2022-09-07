/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:21:27 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 22:02:06 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_count(n) + 1;
	str = (char *)malloc(sizeof(char) * count);
	if (!str)
		return (0);
	if (n < 0)
	{
		n *= -1;
		str[i++] = '-';
	}
	str[--count] = '\0';
	while (i < count)
	{
		str[--count] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
