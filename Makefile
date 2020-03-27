# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/03/27 13:28:22 by cyrillebert      ###   ########.fr        #
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
			Bonus/mini_map.c

LIBFT		= libft/libft.a

NAME		= cub3d

RM			= rm -f

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

MLXFLAGS	= -L ./ -lmlx -framework OpenGL -framework Appkit 

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

${NAME}:	
			make re -C libft
			make clean -C libft
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
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
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) maps/test.cub

re2:		clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) maps/test2.cub

re3:			clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) maps/test3.cub


.PHONY:		all clean fclean re re2 re3 libft
