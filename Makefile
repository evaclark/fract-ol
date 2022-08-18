NAME = fract-ol

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE_PATH = src/
SOURCES = init.c make_fractal.c utils.c window.c test.c Julia.c Mandelbrot.c \
		  mouse.c
SRCS = $(addprefix $(SOURCE_PATH), $(SOURCES))

INCLUDES = ./inc

PRINTFLIB = -Lft_printf -lftprintf -Ift_printf

MLXLIBRARY = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
MINILIBX = mlx

all:
	make -s -C ft_printf
	make -s -C $(MINILIBX)
	$(CC) $(FLAGS) $(SRCS) -I $(INCLUDES) $(PRINTFLIB) $(MLXLIBRARY) -o $(NAME)

clean:

fclean: clean

	make clean -C $(MINILIBX)
	rm -rf $(NAME)

re: fclean all
