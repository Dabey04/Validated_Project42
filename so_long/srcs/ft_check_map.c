/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:16:13 by dabey             #+#    #+#             */
/*   Updated: 2022/06/03 05:39:32 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_test_ber_map(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 4] != '.' || argv[len - 3] != 'b'
		|| argv[len - 2] != 'e' || argv[len - 1] != 'r')
		ft_error_simple("Error\nProblem with map name\n");
}

void	check_left_right_wall(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1 || i < vars->nb_line)
	{
		j = 0;
		while (j < vars->nb_column)
		{
			if (vars->map[i][j] != '1')
				ft_error("Error\nYour map is invalid\n", vars);
			j++;
		}
		i += vars->nb_line - 1;
	}
}

void	check_first_last_wall(t_vars *vars)
{
	int	i;

	i = 1;
	while (i < vars->nb_line - 1)
	{
		if (vars->map[i][0] != '1' || vars->map[i][vars->nb_column - 1] != '1')
			ft_error("Error\nYour map is invalid\n", vars);
		i++;
	}
}

void	check_coll_pos_map(t_vars *vars)
{
	int	i;
	int	j;
	int	exitt;
	int	nb_pos;

	i = 0;
	exitt = 0;
	nb_pos = 0;
	while (i < vars->nb_line)
	{
		j = 0;
		while (j < vars->nb_column)
		{
			if (vars->map[i][j] == 'E')
				exitt++;
			if (vars->map[i][j] == 'C')
				vars->nb_collect++;
			if (vars->map[i][j] == 'P')
				ft_is_few_pos(vars, &nb_pos, i, j);
			j++;
		}
		i++;
	}
	if (nb_pos != 1 || vars->nb_collect < 1 || exitt < 1)
		ft_error("Error\nYour map is invalid\n", vars);
}

void	ft_check_map(t_vars *vars)
{
	check_first_last_wall(vars);
	check_left_right_wall(vars);
	check_coll_pos_map(vars);
	check_line(vars);
}
