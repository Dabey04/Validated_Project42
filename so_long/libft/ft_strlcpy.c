/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:55:53 by dabey             #+#    #+#             */
/*   Updated: 2022/05/07 22:10:53 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = -1;
	while (++i < size - 1 && src[i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (ft_strlen(src));
}
