# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 16:22:07 by moamzil           #+#    #+#              #
#    Updated: 2023/08/02 11:48:41 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=GCC
FLAGS= -Wall -Werror -Wextra -I libft.h
AR=ar cr
RM=rm -rf
FILES= get_next_line get_next_line_utils
OBJ=$(FILES:=.o)
NAME=gnl.a

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c get_next_line.h
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@echo "Cleaning : get next line !"

re: fclean all