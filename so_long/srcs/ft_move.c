/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:15:56 by dabey             #+#    #+#             */
/*   Updated: 2022/06/02 21:48:26 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->nb_line)
	{
		free (vars->map[i]);
		i++;
	}
	free (vars->map);
	free(vars->mlx);
}

void	ft_move_up(t_vars *vars)
{
	if (vars->pos_y == 1 || (vars->pos_y != 0
			&& vars->map[vars->pos_y - 1][vars->pos_x] == '1'))
		return ;
	if (vars->map[vars->pos_y - 1][vars->pos_x] == '0')
	{
		ft_utils_move_up(vars);
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y - 1][vars->pos_x] == 'C')
	{
		ft_utils_move_up(vars);
		vars->nb_collect--;
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y - 1][vars->pos_x] == 'E'
			&& !vars->nb_collect)
	{
		write(1, "Vous avez gagné :)\n", ft_strlen("Vous avez gagné :)\n"));
		mlx_loop_end(vars->mlx);
	}
}

void	ft_move_down(t_vars *vars)
{
	if (vars->pos_y == vars->nb_line - 1 || (vars->pos_y != 0
			&& vars->map[vars->pos_y + 1][vars->pos_x] == '1'))
		return ;
	if (vars->map[vars->pos_y + 1][vars->pos_x] == '0')
	{
		ft_utils_move_down(vars);
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y + 1][vars->pos_x] == 'C')
	{
		ft_utils_move_down(vars);
		vars->nb_collect--;
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y + 1][vars->pos_x] == 'E'
			&& !vars->nb_collect)
	{
		write(1, "Vous avez gagné :)\n", ft_strlen("Vous avez gagné :)\n"));
		mlx_loop_end(vars->mlx);
	}
}

void	ft_move_left(t_vars *vars)
{
	if (vars->pos_x == 1 || (vars->pos_x != 0
			&& vars->map[vars->pos_y][vars->pos_x - 1] == '1'))
		return ;
	if (vars->map[vars->pos_y][vars->pos_x - 1] == '0')
	{
		ft_utils_move_left(vars);
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y][vars->pos_x - 1] == 'C')
	{
		ft_utils_move_left(vars);
		vars->nb_collect--;
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y][vars->pos_x - 1] == 'E'
			&& !vars->nb_collect)
	{
		write(1, "Vous avez gagné :)\n", ft_strlen("Vous avez gagné :)\n"));
		mlx_loop_end(vars->mlx);
	}
}

void	ft_move_right(t_vars *vars)
{
	if (vars->pos_x == vars->nb_column - 1 || (vars->pos_x != 0
			&& vars->map[vars->pos_y][vars->pos_x + 1] == '1'))
		return ;
	if (vars->map[vars->pos_y][vars->pos_x + 1] == '0')
	{
		ft_utils_move_right(vars);
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y][vars->pos_x + 1] == 'C')
	{
		ft_utils_move_right(vars);
		vars->nb_collect--;
		ft_display(vars);
	}
	else if (vars->map[vars->pos_y][vars->pos_x + 1] == 'E'
			&& !vars->nb_collect)
	{
		write(1, "Vous avez gagné :)\n", ft_strlen("Vous avez gagné :)\n"));
		mlx_loop_end(vars->mlx);
	}
}
