/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:23:26 by ccouliba          #+#    #+#             */
/*   Updated: 2021/12/07 16:14:52 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_COLOR_H
# define SO_LONG_COLOR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*
** Regular colors
** \e[0; for regulars colors
** \e[1; for bold colors
** \e[3; for italics
** \e[4; for underlining
** \e[5; for blinking colors
** \e[7; for getting colored background
*/
# define RED "\e[0;31m"
# define BOLD_RED "\e[1;31m"
# define IT_RED "\e[3;31m"
# define U_RED "\e[4;31m"
# define BLINK_RED "\e[5;31m"
# define BG_RED "\e[7;31m"

# define BOLD_GREY "\e[1;30m"
# define GREY "\e[0;30m"
# define BOLD_GREEN "\e[1;32m"
# define GREEN "\e[0;32m"

# define BOLD_YELLOW "\e[1;33m"
# define BLUE "\e[0;34m"
# define BOLD_BLUE "\e[1;34m"

# define BOLD_PURPLE "\e[1;35m"

# define CYAN "\e[0;36m"
# define BOLD_CYAN "\e[1;36m"

# define WHITE "\e[0;37m"
# define BOLD_WHITE "\e[1;37m"
# define BG_WHITE "\e[7;37m"
# define U_WHITE "\e[4;37m"

# define END "\e[0;m"

#endif
