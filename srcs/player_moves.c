/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:24:20 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 14:08:08 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_left(t_mlx *mlx)
{
	mlx->p_x -= OFFSET;
	++mlx->step;
	if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == '1')
	{
		mlx->p_x += OFFSET;
		--mlx->step;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'C')
	{
		mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] = '0';
		++mlx->new_c_flag;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'E' &&
		mlx->new_c_flag == mlx->old_c_flag)
		exit_game(mlx);
	return (EXIT_SUCCESS);
}

int	move_right(t_mlx *mlx)
{
	mlx->p_x += OFFSET;
	++mlx->step;
	if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == '1')
	{
		mlx->p_x -= OFFSET;
		--mlx->step;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'C')
	{
		mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] = '0';
		++mlx->new_c_flag;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'E' &&
			mlx->new_c_flag == mlx->old_c_flag)
		exit_game(mlx);
	return (EXIT_SUCCESS);
}

int	move_up(t_mlx *mlx)
{
	mlx->p_y -= OFFSET;
	++mlx->step;
	if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == '1')
	{
		mlx->p_y += OFFSET;
		--mlx->step;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'C')
	{
		mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] = '0';
		++mlx->new_c_flag;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'E' &&
			mlx->new_c_flag == mlx->old_c_flag)
		exit_game(mlx);
	return (EXIT_SUCCESS);
}

int	move_down(t_mlx *mlx)
{
	mlx->p_y += OFFSET;
	++mlx->step;
	if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == '1')
	{
		mlx->p_y -= OFFSET;
		--mlx->step;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'C')
	{
		mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] = '0';
		++mlx->new_c_flag;
	}
	else if (mlx->map[mlx->p_y / OFFSET][mlx->p_x / OFFSET] == 'E' &&
			mlx->new_c_flag == mlx->old_c_flag)
		exit_game(mlx);
	return (EXIT_SUCCESS);
}

/*
** Associate a key pressing to a movement
** Then refresh the mlx
*/
int	get_key_code(int key_code, t_mlx *mlx)
{
	if (key_code == LEFT)
		move_left(mlx);
	else if (key_code == RIGHT)
		move_right(mlx);
	else if (key_code == UP)
		move_up(mlx);
	else if (key_code == DOWN)
		move_down(mlx);
	else if (key_code == ESC)
	{
		exit_game(mlx);
		return (EXIT_FAILURE);
	}
	mlx_clear_window(mlx->mlx, mlx->win);
	refresh_mlx(mlx);
	ft_putnbr_fd_color(mlx->step, 1, CYAN);
	return (EXIT_SUCCESS);
}
