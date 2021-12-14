/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:53:10 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/14 18:06:08 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
** Define the extension ber
** Define the offset (nb of pixel in a square)
** Define the buffer_size for the read
*/
# define BER_EXT ".ber"
# define OFFSET 32
# define BUFFER_SIZE 2048

/*
** Define keycode
*/
# define RIGHT 100
# define LEFT 97
# define UP 119
# define DOWN 115
# define ESC 65307

/*
** Define error type
*/
# define READING_ERROR "Reading error !"
# define PARSING_ERROR "Parsing error !"
# define ANY_MLX_ERROR "MinilibX error !"
# define ARG_ERROR "Missing map !"

/*
** Define error message
*/
# define FILE_ERROR "-> The given file should end with .ber"
# define FILE_ERROR_2 "-> The file does not exist"
# define FORM_ERROR "-> The given map should be rectangular."
# define CHAR_ERROR "-> Map should only have '0', 'C', 'E', '1' and 'P'."
# define WALL_ERROR "-> Map should be surrounded by '1'."
# define ITEM_ERROR "-> Map should have at least 1 'C', 1 'E' and only 1 'P'."
# define MLX_ERROR "-> Something went wrong with the MinilibX."

/*
** Dfine all xpm path files to load
*/
# define WALL_PATH "./prites/wall.xpm"
# define PLAYER_PATH "./sprites/player.xpm"
# define ITEM_PATH "./sprites/item.xpm"
# define EXIT_PATH "./sprites/exit.xpm"
# define GROUND_PATH "./sprites/ground.xpm"

#endif
