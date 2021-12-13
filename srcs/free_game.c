/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:57:11 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 13:58:05 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_map(char **map)
{
	int	i;

	if (!*map || !map)
		return (EXIT_FAILURE);
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	map = NULL;
	return (EXIT_SUCCESS);
}

int	destroy_mlx(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx->win = NULL;
	mlx_destroy_image(mlx->mlx, mlx->wall);
	mlx->wall = NULL;
	mlx_destroy_image(mlx->mlx, mlx->player);
	mlx->player = NULL;
	mlx_destroy_image(mlx->mlx, mlx->item);
	mlx->item = NULL;
	mlx_destroy_image(mlx->mlx, mlx->exit);
	mlx->exit = NULL;
	mlx_destroy_image(mlx->mlx, mlx->ground);
	mlx->ground = NULL;
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	mlx->mlx = NULL;
	return (EXIT_SUCCESS);
}
