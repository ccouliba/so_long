/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:49 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 17:50:45 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		c_flag;
	int		p_flag;
	int		e_flag;
	int		x;
	int		y;
	int		map_is_valid;
}				t_game;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player;
	void	*item;
	void	*exit;
	char	**map;
	void	*ground;
	int		p_x;
	int		p_y;
	int		x;
	int		y;
	int		width;
	int		height;
	int		new_c_flag;
	int		old_c_flag;
	int		step;
}				t_mlx;

#endif
