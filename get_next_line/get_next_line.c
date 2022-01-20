/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:01:32 by dabey             #+#    #+#             */
/*   Updated: 2020/02/16 18:24:59 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_line(int len_read, char **stock, char **line)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	len = 0;
	while ((*stock)[len] != '\n' && (*stock)[len] != '\0')
		len++;
	if ((*stock)[len] == '\n')
	{
		*line = ft_substr((*stock), 0, len);
		tmp = ft_strdup((*stock + len + 1));
		free(*stock);
		*stock = tmp;
	}
	else
	{
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = NULL;
	}
	if (len_read == 0 && *stock == '\0')
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			len_read;
	char		*buffer;
	static char	*stock = NULL;

	buffer = NULL;
	len_read = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	!(buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
		return (-1);
	stock = (!(stock) ? ft_calloc(sizeof(char), 0) : stock);
	while (len_read > 0 && !(ft_strchr(stock, '\n')))
	{
		if ((len_read = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[len_read] = '\0';
		if (len_read > 0)
			stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	return (gnl_line(len_read, &stock, line));
}
