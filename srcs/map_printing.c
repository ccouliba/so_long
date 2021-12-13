/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_printing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:43:42 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 17:46:02 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Set the player initial position
*/
int	set_player(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->p_x = j * OFFSET;
				mlx->p_y = i * OFFSET;
			}
		}
	}
	return (EXIT_SUCCESS);
}

/*
** First print
** Print map with walls, items, exits and ground
*/
int	print_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->wall,
					j * OFFSET, i * OFFSET);
			else if (mlx->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item,
					j * OFFSET, i * OFFSET);
			else if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
					j * OFFSET, i * OFFSET);
			else
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->ground,
					j * OFFSET, i * OFFSET);
		}
	}
	return (EXIT_SUCCESS);
}

/*
** Second print
** Print map with player, items and exit
*/
int	new_print(t_game *game, t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player,
					j * OFFSET, i * OFFSET);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->item,
					j * OFFSET, i * OFFSET);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->exit,
					j * OFFSET, i * OFFSET);
		}
	}
	return (EXIT_SUCCESS);
}
