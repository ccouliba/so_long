/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:08:59 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 14:01:59 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	objects_are_valid(t_game *game)
{
	game = count_obj(game);
	if (game->p_flag != 1 || game->e_flag <= 0 || game->c_flag <= 0)
	{
		print_error(PARSING_ERROR, ITEM_ERROR, 2, BOLD_RED);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
** 0 if the map is rectangular
** EXIT_FAILURE if it's not
*/
int	form_is_valid(char **s)
{
	int	i;
	int	first_len;

	i = 0;
	first_len = ft_strlen(s[0]);
	while (s[i])
	{
		if (first_len != ft_strlen(s[i]))
		{
			print_error(PARSING_ERROR, FORM_ERROR, 2, BOLD_RED);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

/*
** 0 if the line is valid
** -1 if not
*/
int	lines_are_valid(char **line, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (wall_is_valid(line[0]) != 0 || wall_is_valid(line[nb - 1]) != 0)
		{
			print_error(PARSING_ERROR, WALL_ERROR, 2, BOLD_RED);
			return (EXIT_FAILURE);
		}
		if (char_is_valid(line[i]) != 0)
		{
			print_error(PARSING_ERROR, CHAR_ERROR, 2, BOLD_RED);
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	map_is_valid(char *file, t_game *game)
{
	if (file_is_ber_ext(file) != 0)
		return (EXIT_FAILURE);
	game->map = read_and_split_file(file, game->map);
	if (!game->map)
	{
		free_map(game->map);
		return (EXIT_FAILURE);
	}
	game->x = lines_number(game->map);
	game->y = ft_strlen(game->map[0]);
	if (form_is_valid(game->map) != 0)
		return (EXIT_FAILURE);
	else if (lines_are_valid(game->map, game->x) != 0)
		return (EXIT_FAILURE);
	else if (objects_are_valid(game) != 0)
		return (EXIT_FAILURE);
	game->map_is_valid = 0;
	return (EXIT_SUCCESS);
}
