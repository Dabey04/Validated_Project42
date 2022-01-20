/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:05:49 by dabey             #+#    #+#             */
/*   Updated: 2021/09/24 18:09:24 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"
# define TYPE_PRINT "idcspxXu%"

int				ft_printf(const char *format, ...);
void			print_decemal(va_list *my_list, int *nb_print);
void			print_char(va_list *my_list, int *nb_print);
void			print_string(va_list *my_list, int *nb_print);
void			print_pointer(va_list *my_list, int *nb_print);
void			print_unsigned(va_list *my_list, int *nb_print);
void			print_exalower(va_list *my_list, int *nb_print);
void			print_exaupper(va_list *my_list, int *nb_print);
void			print_percent(va_list *my_list, int *nb_print);
void			ft_remp_tabfunc(void (*function_tab[9])(va_list*, int*));
void			ft_usual(long ptr);
int				ft_printstr(char *str);
char			*ft_uitoa(unsigned int n);
int				ft_find(char format_i, char *type);
int				ft_length_di(int number);
int				ft_length_u(unsigned int number);
int				ft_length_x(long int number);
void			ft_putstr_len(char *s, int len);
void			ft_putstr_fd(char *s, int fd);
int				ft_putnbr_base(long int nbr, char *base);
void			ft_putnbr(int n, int fd);
long int		ft_fill_tab(char *tab, long int num, char *base_to);

#endif
