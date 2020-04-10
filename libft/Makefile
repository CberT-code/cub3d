# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 12:20:26 by cbertola          #+#    #+#              #
#    Updated: 2020/04/09 13:58:59 by cyrillebert      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$(notdir $*).d -MT '$(DEP_DIR)/$(notdir $@)'

# DIRECTORIES
DEP_DIR	= dep
OBJ_DIR	= obj
DIR		= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= libft.a
SRC		= ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c \
		  ft_strnstr.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_bzero.c ft_toupper.c ft_tolower.c ft_memset.c ft_memcpy.c ft_memccpy.c \
		  ft_memmove.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_calloc.c ft_strdup.c \
		  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_replace.c ft_strcmp.c is_tab_full.c \
		  gnl/get_next_line.c gnl/get_next_line_utils.c printf/srcs/ft_printf.c \
		  printf/srcs/ft_flags.c printf/srcs/ft_fct.c printf/srcs/ft_cs.c \
		  printf/srcs/ft_p.c printf/srcs/ft_diu.c printf/srcs/ft_x.c ft_strlen.c
makeSRCB	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ 	:= $(SRC:%.c=$(OBJ_DIR)/%.o)
DEPB	:= $(SRCB:%.c=$(DEP_DIR)/%.d)
OBJB 	:= $(SRCB:%.c=$(OBJ_DIR)/%.o)
$(NAME): $(OBJ)
	ar -rcs $@ $(addprefix obj/, $(notdir $^))
	ranlib $@

all: $(NAME)

clean:
	rm -rf $(DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(OBJB)
	ar -rcs $(NAME) $^ 

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(DIR)
	$(CC) $(CFLAGS) $(DFLAGS) -c $< -o obj/$(notdir $@)

-include $(DEP)

.PHONY: all clean fclean re bonus
