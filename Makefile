NAME = fract-ol

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE_PATH = src/
SOURCES = make_fractal.c window.c img.c main.c Julia.c Mandelbrot.c mouse.c
SRCS = $(addprefix $(SOURCE_PATH), $(SOURCES))

INCLUDES = ./inc

LIBRARY = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
MINILIBX = mlx

all:
	make -s -C $(MINILIBX)
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES) $(LIBRARY) -o $(NAME)

clean:

fclean: clean

	make clean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all
