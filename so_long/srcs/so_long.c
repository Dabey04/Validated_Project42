/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:10:46 by dabey             #+#    #+#             */
/*   Updated: 2022/06/03 02:07:00 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_test(int keycode, t_vars *vars)
{
	if (keycode == 119)
		ft_move_up(vars);
	else if (keycode == 115)
		ft_move_down(vars);
	else if (keycode == 97)
		ft_move_left(vars);
	else if (keycode == 100)
		ft_move_right(vars);
	else if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	draw_tiles(vars);
	return (0);
}

void	draw_tiles_sub(t_vars *vars, int row, int col)
{
	while (row < vars->nb_line)
	{
		col = 0;
		while (col < vars->nb_column)
		{
			if (vars->map[row][col] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img_ptr.img[0], col * TILES, row * TILES);
			else if (vars->map[row][col] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img_ptr.img[1], col * TILES, row * TILES);
			else if (vars->map[row][col] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img_ptr.img[2], col * TILES, row * TILES);
			else if (vars->map[row][col] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img_ptr.img[3], col * TILES, row * TILES);
			else if (vars->map[row][col] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img_ptr.img[4], col * TILES, row * TILES);
			col++;
		}
		row++;
	}
}

void	draw_tiles(t_vars *vars)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	draw_tiles_sub(vars, row, col);
}

void	ft_creat_img(t_vars *vars)
{
	vars->img_ptr.img[0] = mlx_xpm_file_to_image(vars->mlx, "./map/mario.xpm",
			&vars->img_ptr.width, &vars->img_ptr.height);
	ft_check_image(vars, vars->img_ptr.img[0]);
	vars->img_ptr.img[1] = mlx_xpm_file_to_image(vars->mlx, "./map/wall.xpm",
			&vars->img_ptr.width, &vars->img_ptr.height);
	ft_check_image(vars, vars->img_ptr.img[1]);
	vars->img_ptr.img[2] = mlx_xpm_file_to_image(vars->mlx, "./map/exit.xpm",
			&vars->img_ptr.width, &vars->img_ptr.height);
	ft_check_image(vars, vars->img_ptr.img[2]);
	vars->img_ptr.img[3] = mlx_xpm_file_to_image(vars->mlx, "./map/sushi.xpm",
			&vars->img_ptr.width, &vars->img_ptr.height);
	ft_check_image(vars, vars->img_ptr.img[3]);
	vars->img_ptr.img[4] = mlx_xpm_file_to_image(vars->mlx, "./map/0.xpm",
			&vars->img_ptr.width, &vars->img_ptr.height);
	ft_check_image(vars, vars->img_ptr.img[4]);
	draw_tiles(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		ft_error_simple("Error\nFew or too much arguments\n");
	ft_init(&vars);
	ft_test_ber_map(argv[1]);
	ft_creat_map(&vars, argv[1]);
	ft_check_map(&vars);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_error("Error\nProblem with mlx initialization\n", &vars);
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "So_long");
	if (!vars.win)
	{
		free(vars.mlx);
		ft_error("Error\nProblem with window creation\n", &vars);
	}
	ft_creat_img(&vars);
	mlx_hook(vars.win, 17, 1L << 17, mlx_loop_end, vars.mlx);
	mlx_hook(vars.win, 2, 1L << 0, key_test, &vars);
	mlx_loop(vars.mlx);
	close_win(&vars);
	return (0);
}
