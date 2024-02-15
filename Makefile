NAME	= parsing
FILE	= bin/main/main \
		  bin/main/quit_program \
		  bin/read_file/read_map \
		  bin/read_file/tools \
		  bin/read_file/checks \
		  bin/read_file/tools_2 \
		  bin/read_file/read_map_lines
OBJ		= $(FILE:=.o)
SRC		= src/libft/libft.a src/get_next_line/gnl.a
LIBFT 	= src/libft
GETNL	= src/get_next_line
AR		= ar cr
CC		= cc
FLAGS	=
RM		= rm -rf
MK 		= make -C
MKCL	= make clean -C
MKFCL	= make fclean -C

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	$(AR) bin.a $(OBJ)
	$(CC) $(FLAGS) bin.a $(SRC) -o $(NAME)

$(SRC):
	$(MK) $(LIBFT)
	$(MK) $(GETNL)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MKCL) $(LIBFT)
	$(MKCL) $(GETNL)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)
	$(MKFCL) $(LIBFT)
	$(MKFCL) $(GETNL)

re: fclean all
Phony: all clean fclean re
