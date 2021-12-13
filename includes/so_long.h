/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:15:24 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 15:20:09 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "struct.h"
# include "define.h"
# include "so_long_color.h"
# include "../mlx_linux/mlx.h"

/*
** lib functions
*/
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);
int		ft_strcmp(char *a_s1, char *a_s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char *s, char c);

/*
** Reading
*/
int		file_is_ber_ext(char *file_name);
char	**read_and_split_file(char *file_name, char **map);

/*
** Parsing && utils
*/
int		objects_are_valid(t_game *game);
int		form_is_valid(char **s);
int		lines_are_valid(char **line, int nb);
int		map_is_valid(char *file, t_game *game);

int		valid_char(char c);
int		char_is_valid(char *line);
int		wall_is_valid(char *wall);
int		lines_number(char **map);
t_game	*count_obj(t_game *game);

/*
** Get and set differents elements of the map
*/
int		init_map(t_game *game);
int		init_image(t_game *game, t_mlx *mlx);

/*
** Print the map with its elements
*/
int		print_ground(t_mlx *mlx);
int		print_map(t_mlx *mlx);
int		new_print(t_game *game, t_mlx *mlx);
int		set_player(t_mlx *mlx);
int		refresh_mlx(t_mlx *mlx);

/*
** Moving the player
*/
int		move_left(t_mlx *mlx);
int		move_right(t_mlx *mlx);
int		move_up(t_mlx *mlx);
int		move_down(t_mlx *mlx);
int		get_key_code(int key_code, t_mlx *mlx);
int		player_move(t_mlx *mlx);

/*
** Error
*/
void	ft_putstr_fd_color(char *s, int fd, char *color);
void	ft_putnbr_fd_color(int nbr, int fd, char *color);
void	get_msg_error(char *msg, int fd, char *color);
void	print_arg_error(int ac, int fd, char *color);
void	print_error(char *error_type, char *error_msg, int fd, char *color);

/*
** Close, destroy and free
*/
int		close_mlx(t_mlx *mlx);
int		main(int ac, char **av);
int		free_map(char **map);
int		destroy_mlx(t_mlx *mlx);
int		exit_game(t_mlx *mlx);

void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
#endif
