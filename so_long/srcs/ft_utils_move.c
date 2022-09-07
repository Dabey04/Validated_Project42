/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:02:26 by dabey             #+#    #+#             */
/*   Updated: 2022/06/03 01:13:42 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->nb_column = 0;
	vars->nb_line = 0;
	vars->img_ptr.width = 0;
	vars->img_ptr.height = 0;
	vars->width = 0;
	vars->width = 0;
	vars->pos_x = 0;
	vars->pos_y = 0;
	vars->nb_collect = 0;
	vars->nb_mov = 0;
	vars->img_ptr.img[0] = 0;
	vars->img_ptr.img[1] = 0;
	vars->img_ptr.img[2] = 0;
	vars->img_ptr.img[3] = 0;
	vars->img_ptr.img[4] = 0;
}

void	ft_utils_move_up(t_vars *vars)
{	
	vars->map[vars->pos_y][vars->pos_x] = '0';
	vars->map[vars->pos_y - 1][vars->pos_x] = 'P';
	vars->pos_y--;
	vars->nb_mov++;
}

void	ft_utils_move_down(t_vars *vars)
{
	vars->map[vars->pos_y][vars->pos_x] = '0';
	vars->map[vars->pos_y + 1][vars->pos_x] = 'P';
	vars->pos_y++;
	vars->nb_mov++;
}

void	ft_utils_move_left(t_vars *vars)
{
	vars->map[vars->pos_y][vars->pos_x] = '0';
	vars->map[vars->pos_y][vars->pos_x - 1] = 'P';
	vars->pos_x--;
	vars->nb_mov++;
}

void	ft_utils_move_right(t_vars *vars)
{
	vars->map[vars->pos_y][vars->pos_x] = '0';
	vars->map[vars->pos_y][vars->pos_x + 1] = 'P';
	vars->pos_x++;
	vars->nb_mov++;
}
