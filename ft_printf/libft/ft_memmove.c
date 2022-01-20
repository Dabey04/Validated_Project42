/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:19:49 by dabey             #+#    #+#             */
/*   Updated: 2019/11/29 19:41:56 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*p_dst;
	const char	*p_src;

	i = -1;
	p_dst = (char *)dst;
	p_src = (const char *)src;
	if (!dst && !src)
		return (0);
	if (len == 0)
		return (p_dst);
	if (p_dst < p_src)
	{
		while (++i < len)
			p_dst[i] = p_src[i];
	}
	else
	{
		while (++i < len)
			p_dst[(len - 1) - i] = p_src[(len - 1) - i];
	}
	return (dst);
}
