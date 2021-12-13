/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:34:53 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/07 16:51:24 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
** Print error with certain colors 
*/

void	ft_putstr_fd_color(char *s, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(END, fd);
}

void	ft_putnbr_fd_color(int nbr, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putnbr_fd(nbr, fd);
	ft_putstr_fd(END, fd);
	ft_putchar_fd('\n', fd);
}

void	get_msg_error(char *msg, int fd, char *color)
{
	ft_putstr_fd_color(msg, fd, color);
	ft_putchar_fd('\n', fd);
}

void	print_arg_error(int ac, int fd, char *color)
{
	char	*msg;

	msg = "-> You forgot to choose a map.";
	if (ac != 2)
	{
		print_error(ARG_ERROR, msg, fd, color);
		exit(1);
	}
}

void	print_error(char *error_type, char *error_msg, int fd, char *color)
{
	ft_putstr_fd_color("ERROR :", fd, BG_RED);
	ft_putchar_fd(' ', fd);
	get_msg_error(error_type, fd, color);
	get_msg_error(error_msg, fd, color);
	exit(1);
}
