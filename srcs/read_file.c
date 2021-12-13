/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:31:00 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/13 14:03:59 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Check if there is a double \n (double maps in one file)
*/
static int	single_map(char *s)
{
	char	*msg;

	msg = "-> Something went wrong during the reading.\n";
	while (*s)
	{
		if (*s == '\n' && *(s + 1) == '\n')
		{
			print_error(READING_ERROR, msg, 2, BOLD_RED);
			return (EXIT_FAILURE);
		}
		++s;
	}
	return (EXIT_SUCCESS);
}

/*
** 0 if the extension is .ber
** -1 is it's not
*/
int	file_is_ber_ext(char *file_name)
{
	int		dot;
	char	*ext;

	dot = 0;
	ext = NULL;
	if (file_name)
	{
		dot = ft_strlen(file_name) - 4;
		ext = &(file_name[dot]);
		if (*ext && *file_name != '.' && ft_strcmp(ext, BER_EXT) == 0)
			return (EXIT_SUCCESS);
		else
		{
			print_error(PARSING_ERROR, FILE_ERROR, 2, BOLD_RED);
			return (EXIT_FAILURE);
		}
	}
	print_error(PARSING_ERROR, FILE_ERROR_2, 2, BOLD_RED);
	return (EXIT_FAILURE);
}

/*
** Read the file
** Then split it at '\n' and return a str
*/
char	**read_and_split_file(char *file_name, char **map)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*msg;
	int		res;
	int		fd;

	fd = open(file_name, O_RDONLY);
	res = read(fd, buffer, BUFFER_SIZE);
	msg = "-> Make sure the file exists or is not hidden.";
	if (res == -1 || res == 0)
	{
		close(fd);
		print_error(READING_ERROR, msg, 2, BOLD_RED);
		return (NULL);
	}
	buffer[res] = '\0';
	if (single_map(buffer) != 0)
		exit(1);
	map = ft_split(buffer, '\n');
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}
