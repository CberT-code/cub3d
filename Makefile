# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/04/25 12:47:44 by cbertola         ###   ########.fr        #
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

NAME = 		Cub3D

FLAGS =		-Wall -Werror -Wextra

INC =		./minilibx_linux/

LIB =		./minilibx_linux/

GFX_FLAGS =	-framework OpenGL -framework AppKit

LIB_FLAGS =	-lX11 -lXext -lm -lbsd

LOGFILE		= $(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`

all: 		$(NAME)

$(NAME):	
			make -C libft
			make -C minilibx_linux
			clang $(FLAGS) $(SRCS) libft/libft.a minilibx_linux/libmlx_Linux.a $(LIB_FLAGS) -o $(NAME)
			./Cub3D maps/test.cub --save

libft:
			make re -C libft
			make clean -C libft

minilibx_linux:
			make re -C minilibx_linux

git:		fclean
			git add -A
			git add *
			git commit -u -m "$(LOGFILE) $(MSG)"
			git push

clean:
			make clean -C libft
			rm -f $(NAME)
			rm -f $(NAME)_bonus
			rm -f image.bmp

fclean:		
			make fclean -C libft
			make clean -C minilibx_linux
			rm -f ${NAME}
			rm -f $(NAME)_bonus
			rm -f image.bmp

re: 		clean
			clang $(FLAGS) $(SRCS) libft/libft.a minilibx_linux/libmlx_Linux.a $(LIB_FLAGS) -o $(NAME) 
			./Cub3D maps/test2.cub

bonus:		clean
			clang $(FLAGS) $(BONUS) libft/libft.a minilibx_linux/libmlx_Linux.a  $(LIB_FLAGS) -o $(NAME)_bonus
			./Cub3D_bonus maps/test3.cub

norm:
			~/.norminette/norminette.rb main.c
			~/.norminette/norminette.rb cub3d.h
			~/.norminette/norminette.rb parsing
			~/.norminette/norminette.rb srcs
			~/.norminette/norminette.rb libft
			~/.norminette/norminette.rb Bonus

.PHONY:		all clean fclean re bonus libft git minilibx_linux norm
