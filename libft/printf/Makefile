# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2019/12/10 11:49:51 by cbertola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS		= srcs/ft_printf.c srcs/ft_flags.c srcs/ft_fct.c \
				srcs/ft_cs.c srcs/ft_p.c srcs/ft_diu.c srcs/ft_x.c

OBJS		= ${SRCS:.c=.o}

LIBFT		= libft

NAME_LIBFT	= libft.a

NAME		= libftprintf.a

RM			= rm -f

CC			= gcc

CFLAGS		= -I includes -Wall -Wextra -Werror

all:		${NAME}

${NAME}:    ${OBJS}
			@make -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)
clean:      
			@make -C $(LIBFT) clean
			${RM} ${OBJS}

fclean:		clean
			cd ${LIBFT} && ${RM} ${NAME_LIBFT}
			${RM} ${NAME}

re:			fclean all
.PHONY:		all clean fclean re
