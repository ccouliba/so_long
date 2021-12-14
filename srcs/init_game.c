/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:05:36 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/14 19:01:05 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** 0 if success
** Init the game struct (if the parsing returns SUCCESS)
*/
int	init_map(t_game *game)
{
	if (game->map_is_valid == 0)
	{
		game = count_obj(game);
		game->height = game->x * OFFSET;
		game->width = game->y * OFFSET;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

/*
** 0 for success
** Getting the sprites of objects 
** Init the mlx with the parametersof the game and
*/
int	init_image(t_game *game, t_mlx *mlx)
{
	mlx->new_c_flag = 0;
	mlx->old_c_flag = game->c_flag;
	mlx->map = game->map;
	mlx->x = game->x;
	mlx->y = game->y;
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, WALL_PATH, &mlx->x, &mlx->y);
	if (!mlx->wall)
		exit_game(mlx);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, PLAYER_PATH,
			&mlx->x, &mlx->y);
	if (!mlx->player)
		exit_game(mlx);
	mlx->item = mlx_xpm_file_to_image(mlx->mlx, ITEM_PATH, &mlx->x, &mlx->y);
	if (!mlx->item)
		exit_game(mlx);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, EXIT_PATH, &mlx->x, &mlx->y);
	if (!mlx->exit)
		exit_game(mlx);
	mlx->ground = mlx_xpm_file_to_image(mlx->mlx, GROUND_PATH,
			&mlx->x, &mlx->y);
	if (!mlx->ground)
		exit_game(mlx);
	return (EXIT_SUCCESS);
}
