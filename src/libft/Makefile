# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 05:08:05 by moamzil           #+#    #+#              #
#    Updated: 2023/12/03 23:14:52 by moamzil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
FLAGS= -Wall -Werror -Wextra -I libft.h
AR=ar cr
RM=rm -rf
FILES= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_strlen \
       ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
       ft_strnstr ft_strlcpy ft_strlcat ft_atoi ft_strdup \
       ft_substr ft_strjoin ft_split ft_strtrim ft_itoa ft_strmapi \
       ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_isprint \
       ft_putnbr_fd ft_memcpy ft_memmove ft_memset \
       ft_memcmp ft_memchr ft_bzero ft_calloc ft_striteri
OBJ=$(FILES:=.o)
NAME=libft.a

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
