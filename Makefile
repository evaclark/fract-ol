NAME = fract-ol

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE_PATH = src/
SOURCES = window.c
SRCS = $(SOURCE_PATH)$(SOURCES)

LIBRARY = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
MINILIBX = mlx

all:
	make -s -C $(MINILIBX)
	$(CC) $(FLAGS) $(SRCS)  $(LIBRARY) -o $(NAME)

clean:

fclean: clean

	make clean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all
