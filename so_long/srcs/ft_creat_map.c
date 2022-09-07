/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:41:41 by dabey             #+#    #+#             */
/*   Updated: 2022/06/03 05:23:17 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_read_map(char *argv, t_vars **vars)
{
	int		bol;
	int		fd;
	char	c;
	int		nb_column;

	bol = 1;
	nb_column = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1 || read(fd, &c, 0) == -1)
		ft_error_simple("Error\nProblem with map type\n");
	ft_compt_line_map(vars, fd, nb_column, bol);
	close(fd);
}

void	ft_zero_map(char *map, int nb_column)
{
	int	i;

	i = 0;
	while (i < nb_column)
	{
		map[i] = '0';
		i++;
	}
	map[i] = '\0';
}

void	ft_malloc_map(t_vars **vars)
{
	int	i;
	int	j;

	i = 0;
	(*vars)->map = (char **)malloc(sizeof(char *) * (*vars)->nb_line);
	if (!(*vars)->map)
		return ;
	while (i < (*vars)->nb_line)
	{
		(*vars)->map[i] = (char *)malloc(sizeof(char) * (*vars)->nb_column + 1);
		j = 0;
		if (!(*vars)->map[i])
		{
			while (i >= 0)
			{
				free ((*vars)->map[i - 1]);
				i--;
			}
			free((*vars)->map);
			return ;
		}
		else
			ft_zero_map((*vars)->map[i], (*vars)->nb_column);
		i++;
	}
}

void	ft_fill_map(t_vars **vars, char *argv)
{
	int		i;
	int		j;
	int		fd;
	char	c;

	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error_simple("Error\nProblem with map name\n");
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			(*vars)->map[i][j] = '\0';
			i++;
			j = 0;
		}
		else
		{
			(*vars)->map[i][j] = c;
			j++;
		}
	}
	close(fd);
}

void	ft_creat_map(t_vars *vars, char *argv)
{
	ft_read_map(argv, &vars);
	ft_malloc_map(&vars);
	ft_fill_map(&vars, argv);
	vars->height = TILES * vars->nb_line;
	vars->width = TILES * vars->nb_column;
}
