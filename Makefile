# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 02:06:32 by ccouliba          #+#    #+#              #
#    Updated: 2021/12/14 18:03:49 by ccouliba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ANSI COLORS
_GREY		=	$'\033[0;30m
_RED		=	$'\033[0;31m
_GREEN		=	$'\033[0;92m
_YELLOW		=	$'\033[0;33m
_BLUE		=	$'\033[0;34m
_U_BLUE		=	$'\033[4;34m
_BLINK_BLUE	=	$'\033[5;94m
_PURPLE		=	$'\033[0;35m
_CYAN		=	$'\033[0;96m
_WHITE		=	$'\033[0;37m
_END		=	$'\033[0;m
_BOLD		=	$'\033[1m

NAME		=	so_long

SRCS		=	srcs/parsing_utils.c \
			srcs/split_and_utils.c \
			srcs/lib_utils.c \
			srcs/read_file.c \
			srcs/map_parsing.c \
			srcs/init_game.c \
			srcs/map_printing.c \
			srcs/player_moves.c \
			srcs/free_game.c \
			srcs/so_long.c \
			srcs/print_error.c

LINUX		= -I /usr/include -L /usr/lib/ -lmlx -L mlx_linux -I mlx_linux -lXext -l X11 -lm -lz

CC			= clang

RM 			= rm -rf

CFLAGS		= -Wall -Wextra -Werror #-g3 -fsanitize=address

DEBUG =
ifdef true
CFLAGS += -fsanitize=address
endif

PATH_MLX	= ./mlx_linux

OBJS		= ${SRCS:.c=.o}

all:	${NAME}

${NAME}: ${OBJS}
	make -C $(PATH_MLX) all
	${CC} ${CFLAGS} ${OBJS} ${LINUX} -o ${NAME}
	@echo "[$(_CYAN)Creating objects$(_END) : $(_GREEN)done$(_END)]"
	@echo "[$(_CYAN)Name of the a.out file$(_END) : $(_BLINK_BLUE)$(NAME)$(_END)]"
	@echo "\t\t\tall"
	@echo "\t\t\tclean"
	@echo "Existing rules : \tfclean"
	@echo "\t\t\tre"
	@echo "\t\t\tleak (valgrind + a.out + map)"

%.o: %.c
	$(CC) ${CFLAGS} -I /usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make -C $(PATH_MLX) clean
	@echo "[$(_CYAN)Cleaning MinilibX$(_END) : $(_GREEN)done$(_END)]"
	${RM} ${OBJS}
	@echo "[$(_CYAN)Removing objects$(_END) : $(_GREEN)done$(_END)]$(_END)"

fclean:	clean
	# make -C $(PATH_MLX) clean
	${RM} ${NAME} ${NAME_DEBUG}
	@echo "[$(_CYAN)Removing$(_END) $(_BLINK_BLUE)$(NAME)$(_END) : $(_GREEN)done$(_END)]"

re:			fclean all

leak:	re
	@echo "Enter argument(file name without the path)"
	@echo -n "> "
	@read path_file
	valgrind ./${NAME} ${path_file}

.PHONY:		all clean fclean re leak
