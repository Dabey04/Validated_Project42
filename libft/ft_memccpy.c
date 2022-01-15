/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:06:04 by dabey             #+#    #+#             */
/*   Updated: 2019/11/25 21:03:41 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	while (n-- > 0)
		if ((*d++ = *s++) == (char)c)
			return (d);
	return (NULL);
}
