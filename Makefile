NAME	= cub3d

MLX = minilibx-linux/

MLX_A   = $(addprefix $(MLX), libmlx.a)




CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -lX11 -lXext -Imlx -lm

SRCS = main.c key_hook.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c utils.c player.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_A) $(MLX_FLAGS) -o $(NAME)
$(MLX_A): 
	make -s -C $(MLX)

clean:
	rm -f $(OBJECTS)
	make -s -C $(MLX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re