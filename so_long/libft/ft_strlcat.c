/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:38:41 by dabey             #+#    #+#             */
/*   Updated: 2019/11/15 17:24:46 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int			i;
	int			j;
	size_t		len;

	i = 0;
	j = 0;
	len = ft_strlen(dest);
	while (dest[i] && i < (int)size)
		i++;
	while (src[j] && i < (int)(size - 1))
		dest[i++] = src[j++];
	if (size != 0 && size >= len)
		dest[i] = '\0';
	if (size < len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + len);
}
