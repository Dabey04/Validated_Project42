/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:11:36 by dabey             #+#    #+#             */
/*   Updated: 2022/06/03 05:39:36 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define TILES 64

typedef struct s_img {
	void	*img[5];
	int		width;
	int		height;
}				t_img;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	t_img	img_ptr;
	int		pos_x;
	int		pos_y;
	int		width;
	int		height;
	int		nb_line;
	int		nb_column;
	int		nb_collect;
	int		nb_mov;
}				t_vars;

//**************so_long.c**************

int		key_test(int keycode, t_vars *vars);
void	draw_tiles(t_vars *vars);
void	ft_creat_img(t_vars *vars);
//**************ft_creat_map.c ***********

void	ft_read_map(char *argv, t_vars **vars);
void	ft_zero_map(char *map, int nb_column);
void	ft_malloc_map(t_vars **vars);
void	ft_fill_map(t_vars **vars, char *argv);
void	ft_creat_map(t_vars *vars, char *argv);
//**************ft_move.c**************

void	ft_free(t_vars *vars);
void	ft_move_up(t_vars *vars);
void	ft_move_down(t_vars *vars);
void	ft_move_left(t_vars *vars);
void	ft_move_right(t_vars *vars);
//**************ft_check_map.c*************

void	ft_test_ber_map(char *argv);
void	check_left_right_wall(t_vars *vars);
void	check_first_last_wall(t_vars *vars);
void	check_coll_pos_map(t_vars *vars);
void	ft_check_map(t_vars *vars);
//**************ft_utils_move.c**************

void	ft_init(t_vars *vars);
void	ft_utils_move_up(t_vars *vars);
void	ft_utils_move_down(t_vars *vars);
void	ft_utils_move_left(t_vars *vars);
void	ft_utils_move_right(t_vars *vars);
//**************ft_err_close.c**************

void	ft_error_simple(char *message);
void	ft_error(char *message, t_vars *vars);
void	close_win(t_vars *vars);
void	ft_display(t_vars *vars);
void	ft_is_few_pos(t_vars *vars, int *nb_pos, int i, int j);
//**************test_img_load.c **************

void	ft_check_image(t_vars *vars, void *img);
char	ft_compt_line_map(t_vars **vars, int fd, int nb_column, int bol);
void	check_line(t_vars *vars);

#endif
