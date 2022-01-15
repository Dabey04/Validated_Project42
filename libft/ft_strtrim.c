/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:55:44 by dabey             #+#    #+#             */
/*   Updated: 2019/11/27 19:24:56 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]) != NULL)
		begin++;
	len = ft_strlen(&s1[begin]);
	if (len != 0)
		while (s1[begin + len - 1]
				&& ft_strchr(set, s1[begin + len - 1]) != NULL)
			len--;
	return (ft_substr(s1, begin, len));
}
