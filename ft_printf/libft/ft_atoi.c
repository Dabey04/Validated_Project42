/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:33:33 by dabey             #+#    #+#             */
/*   Updated: 2019/11/14 18:44:46 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	res;

	i = 0;
	nb = 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\n' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		nb = -nb;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * nb);
}
