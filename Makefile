# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/04/21 08:05:03 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		= main.c \
			parsing/parsing.c \
			parsing/parsing_elem.c \
			parsing/full_map.c \
			parsing/error_free.c \
			parsing/init_structures.c \
			srcs/move_player.c \
			srcs/image.c \
			srcs/raycasting.c \
			srcs/radar.c \
			srcs/vector.c \
			srcs/utils.c \
			srcs/bmp.c \
			srcs/sprite.c

BONUS		= Bonus/main.c \
			Bonus/parsing/parsing.c \
			Bonus/parsing/parsing_elem.c \
			Bonus/parsing/full_map.c \
			Bonus/parsing/error_free.c \
			Bonus/parsing/init_structures.c \
			Bonus/srcs/move_player.c \
			Bonus/srcs/image.c \
			Bonus/srcs/raycasting.c \
			Bonus/srcs/radar.c \
			Bonus/srcs/vector.c \
			Bonus/srcs/utils.c \
			Bonus/srcs/bmp.c \
			Bonus/srcs/sprite.c \
			Bonus/srcs/mini_map.c

LIBFT		= libft/libft.a

NAME		= cub3d

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

MLXFLAGS	= -L ./ -lmlx -framework OpenGL -framework Appkit 

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

${NAME}:	
			make -C libft
			make clean -C libft
			gcc $(CFLAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) maps/test.cub

libft:
			make re -C libft
			make clean -C libft

clean:      
			make clean -C libft
			rm -f $(NAME)

fclean:
			make fclean -C libft
			rm -f ${NAME}

git:		fclean
			git add -A
			git add *
			git commit -u -m "$(LOGFILE) $(MSG)"
			git push

all:		${NAME}

re:			clean
			gcc $(CFLAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) maps/test.cub

bonus:		clean
			gcc $(CFLAGS) $(MLXFLAGS) $(BONUS) $(LIBFT) -o $(NAME)
			./$(NAME) maps/test2.cub

.PHONY:		all clean fclean re libft bonus
