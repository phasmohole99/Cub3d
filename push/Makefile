NAME	= parsing
FILE	= bin/main/main \
		  bin/main/quit_program \
		  bin/read_file/read_map \
		  bin/read_file/tools \
		  bin/read_file/checks \
		  bin/read_file/tools_2 \
		  bin/read_file/read_map_lines \
		  bin/read_file/map_checker \
		  bin/start_game/start_game \
		  bin/read_file/tools_3
OBJ		= $(FILE:=.o)
SRC		= src/libft/libft.a src/get_next_line/gnl.a
LIBFT 	= src/libft
GETNL	= src/get_next_line
AR		= ar cr
CC		= cc
FLAGS	= -W -W -W 
RM		= rm -rf
MK 		= make -C
MKCL	= make clean -C
MKFCL	= make fclean -C
LIB_DIR = /Users/mrital-/Desktop/push//Cub/include/libmlx42.a
GLFW_DIR = /Users/mrital-/Desktop/push//Cub/include/libglfw3.a


all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	$(AR) bin.a $(OBJ)
	$(CC) $(FLAGS) bin.a $(SRC) ${GLFW_DIR} ${LIB_DIR} -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)
	$(RM) bin.a
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
