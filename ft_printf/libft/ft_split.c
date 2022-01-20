/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:14:51 by dabey             #+#    #+#             */
/*   Updated: 2019/11/25 21:44:53 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_w(char const *s, char c)
{
	int	len_w;

	len_w = 0;
	while (*s != c && *s != '\0')
	{
		len_w++;
		s++;
	}
	return (len_w);
}

static int	ft_count_w(char const *s, char c)
{
	int	count_w;

	count_w = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count_w++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (count_w);
}

char	**ft_malloc_tab(int count_w)
{
	char	**tab;

	tab = NULL;
	tab = (char **)malloc((count_w + 1) * sizeof(char *));
	if (!tab)
		return (0);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count_w;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	count_w = ft_count_w(s, c);
	tab = ft_malloc_tab(count_w);
	while (i < count_w)
	{
		j = 0;
		while (*s == c)
			s++;
		tab[i] = (char *)malloc(sizeof(char) * (ft_len_w(s, c) + 1));
		if (!tab[i])
			return (0);
		while (*s != c && *s != '\0')
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
