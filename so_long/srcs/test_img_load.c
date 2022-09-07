/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_img_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 02:01:24 by dabey             #+#    #+#             */
/*   Updated: 2022/06/03 05:56:00 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_image(t_vars *vars, void *img)
{
	if (!img)
	{
		write(2, "Error\nProblem with image loading\n",
			ft_strlen("Error\nProblem with image loading\n"));
		close_win(vars);
		exit (1);
	}
}

char	ft_compt_line_map(t_vars **vars, int fd, int nb_column, int bol)
{
	char	c;

	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			bol = 0;
			(*vars)->nb_line++;
			if (nb_column != (*vars)->nb_column)
				ft_error_simple("Error\nProblem with nb_column\n");
			nb_column = 0;
		}
		else
		{
			nb_column++;
			if (bol == 1)
				(*vars)->nb_column += 1;
			else
				(*vars)->nb_column += 0;
		}
	}
	if (c != '\n')
		(*vars)->nb_line++;
	return (c);
}

void	check_line(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->nb_line)
	{
		j = 0;
		while (vars->map[i][j] && j < vars->nb_column)
		{
			if (vars->map[i][j] != 'P' && vars->map[i][j] != 'E'
			&& vars->map[i][j] != 'C' && vars->map[i][j] != '1'
			&& vars->map[i][j] != '0' && vars->map[i][j] != '\0')
				ft_error("Error\nYour map is invalid\n", vars);
			j++;
		}
		i++;
	}
}
