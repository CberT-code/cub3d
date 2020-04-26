# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/04/26 12:24:11 by cbertola         ###   ########.fr        #
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
BONUS		= Bonus/main_bonus.c \
			Bonus/parsing/parsing_bonus.c \
			Bonus/parsing/parsing_elem_bonus.c \
			Bonus/parsing/full_map_bonus.c \
			Bonus/parsing/error_free_bonus.c \
			Bonus/parsing/init_structures_bonus.c \
			Bonus/srcs/move_player_bonus.c \
			Bonus/srcs/image_bonus.c \
			Bonus/srcs/raycasting_bonus.c \
			Bonus/srcs/radar_bonus.c \
			Bonus/srcs/vector_bonus.c \
			Bonus/srcs/utils_bonus.c \
			Bonus/srcs/bmp_bonus.c \
			Bonus/srcs/sprite_bonus.c \
			Bonus/srcs/mini_map_bonus.c

LIBFT		= libft/libft.a

NAME		= Cub3D

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

all:		${NAME}

libft:
			make re -C libft
			make clean -C libft

clean:      
			make clean -C libft
			rm -f $(NAME)
			rm -f $(NAME)_bonus
			rm -f image.bmp

fclean:
			make fclean -C libft
			rm -f ${NAME}
			rm -f $(NAME)_bonus
			rm -f image.bmp

re:			clean
			gcc $(CLFAGS) $(MLXFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
			./$(NAME) maps/test.cub

bonus:		clean
			clang $(FLAGS) $(BONUS) $(MLXFLAGS) libft/libft.a $(LIB_FLAGS) -o $(NAME)_bonus
			./Cub3D_bonus maps/test3.cub

git:		fclean
			git add -A
			git add *
			git commit -u -m "$(LOGFILE) $(MSG)"
			git push
norm:
			~/.norminette/norminette.rb main.c
			~/.norminette/norminette.rb cub3d.h
			~/.norminette/norminette.rb parsing
			~/.norminette/norminette.rb srcs
			~/.norminette/norminette.rb libft
			~/.norminette/norminette.rb Bonus

.PHONY:		all clean fclean re bonus libft norm
