/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:02:09 by dabey             #+#    #+#             */
/*   Updated: 2022/06/03 01:43:12 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_simple(char *message)
{
	write(2, message, ft_strlen(message));
	exit (1);
}

void	ft_error(char *message, t_vars *vars)
{
	write(2, message, ft_strlen(message));
	ft_free(vars);
	exit (1);
}

void	close_win(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (vars->img_ptr.img[i])
			mlx_destroy_image(vars->mlx, vars->img_ptr.img[i]);
		i++;
	}
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free(vars);
}

void	ft_display(t_vars *vars)
{
	write(1, "movement = ", ft_strlen("movement = "));
	ft_putnbr_fd (vars->nb_mov, 1);
	write(1, "\n", 1);
}

void	ft_is_few_pos(t_vars *vars, int *nb_pos, int i, int j)
{
	if (*nb_pos != 1)
	{
		vars->pos_x = j;
		vars->pos_y = i;
		*nb_pos = 1;
	}
	else
		ft_error("Error\nYour map is invalid\n", vars);
}
