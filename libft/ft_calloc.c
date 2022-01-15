/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:09:22 by dabey             #+#    #+#             */
/*   Updated: 2019/11/17 20:42:38 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(dst = malloc(count * size)))
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
