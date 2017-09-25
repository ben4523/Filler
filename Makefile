# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybitton <ybitton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 10:18:53 by ybitton           #+#    #+#              #
#    Updated: 2017/05/12 10:25:59 by ybitton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ybitton.filler

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

LIB   = ./libft/libft.a

SRC =	./srcs/main.c \
		./srcs/get_data_coor.c \
		./srcs/get_data_pc.c \
		./srcs/check_if_fit.c \
		./srcs/filler.c \
		./srcs/strat_print.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)
	@echo "\x1b[35m" [~Compilation done~] "\x1b[0m"

clean :
	@make -C ./libft clean
	@rm -f $(OBJ)
	@echo "\x1b[32m" [~Folders cleaned~] "\x1b[0m"

fclean : clean
	@rm -f $(NAME) $(LIB)

re : fclean all

.PHONY: all clean fclean re
