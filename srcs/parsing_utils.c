/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:06:25 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 14:09:08 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** 0 if character is ok
** EXIT_FAILURE if there is a non wanted character
*/
int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/*
** 0 if chars are ok in the line
** EXIT_FAILURE if it's not
*/
int	char_is_valid(char *line)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line);
	while (++i < len)
	{
		if (line[0] != '1')
			return (EXIT_FAILURE);
		if (valid_char(line[i]) != 0)
			return (EXIT_FAILURE);
		if (line[len - 1] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
** 0 if the wall is valid
** EXIT_FAILURE if not
*/
int	wall_is_valid(char *wall)
{
	while (*wall)
	{
		if (*wall != '1')
			return (EXIT_FAILURE);
		++wall;
	}
	return (EXIT_SUCCESS);
}

/*
** Count the number of lines
*/
int	lines_number(char **map)
{
	int	l_nb;
	int	c_nb;

	l_nb = -1;
	while (map[++l_nb])
	{
		c_nb = 0;
		while (map[l_nb][c_nb])
			++c_nb;
	}
	return (l_nb);
}

/*
** Count the number of item (C, E and P)
*/
t_game	*count_obj(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->c_flag = 0;
	game->e_flag = 0;
	game->p_flag = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
				++game->c_flag;
			else if (game->map[i][j] == 'E')
				++game->e_flag;
			else if (game->map[i][j] == 'P')
				++game->p_flag;
		}
	}
	return (game);
}
