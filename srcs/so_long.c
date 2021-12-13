/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:18:12 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 15:43:38 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Get the new position of the player after each move
*/
int	refresh_mlx(t_mlx *mlx)
{
	print_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->player, mlx->p_x,
		mlx->p_y);
	return (EXIT_SUCCESS);
}

/*
** Clear the mlx and free what i have to free
** Then exit properly
*/
int	exit_game(t_mlx *mlx)
{
	free_map(mlx->map);
	destroy_mlx(mlx);
	exit(1);
	return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_mlx	mlx;

	mlx.step = 0;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		print_error(ANY_MLX_ERROR, ANY_MLX_ERROR, 2, BOLD_RED);
	print_arg_error(ac, 2, BOLD_RED);
	if (map_is_valid(av[1], &game) != 0)
		return (1);
	init_map(&game);
	mlx.win = mlx_new_window(mlx.mlx, game.width, game.height, "SO_LONG");
	if (!mlx.win)
		print_error(ANY_MLX_ERROR, ANY_MLX_ERROR, 2, BOLD_RED);
	mlx_expose_hook(mlx.win, refresh_mlx, &mlx);
	init_image(&game, &mlx);
	print_map(&mlx);
	new_print(&game, &mlx);
	set_player(&mlx);
	mlx_key_hook(mlx.win, get_key_code, &mlx);
	mlx_hook(mlx.win, 17, 0L, exit_game, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
