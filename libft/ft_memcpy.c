/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:16:52 by dabey             #+#    #+#             */
/*   Updated: 2019/11/26 19:31:44 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t len)
{
	size_t	i;

	i = 0;
	if (!str1 && !str2)
		return (NULL);
	while (i < len)
	{
		((unsigned char*)str1)[i] = ((unsigned char*)str2)[i];
		i++;
	}
	return (str1);
}
