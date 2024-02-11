NAME = fractol

SRCS = main.c additional_hooks.c utils.c float_conversion.c error_handling.c initialise.c Mandelbrot.c hooks.c Julia.c extra_utils.c

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = fractol.h

START = cd mlx && make

all: $(NAME)

$(NAME): $(OBJ)
	@$(START)
	@$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)
	make -C mlx clean

re: fclean all fractol re