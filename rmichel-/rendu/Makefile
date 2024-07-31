NAME	= cub3d

MLX = minilibx-linux/

MLX_A   = $(addprefix $(MLX), libmlx.a)




CC = cc

CFLAGS = -g

MLX_FLAGS = -lX11 -lXext -Imlx -lm

SRCS =	raycast.c calc.c parsing.c create_img.c \
		init_values.c map.c key_hook.c minimap.c\
		ft_strlen.c ft_substr.c ft_strtrim.c ft_memset.c ft_bzero.c ft_memcpy.c ft_calloc.c\
		main.c	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_A) $(MLX_FLAGS) -o $(NAME)
$(MLX_A): 
	make -s -C $(MLX)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -s -C $(MLX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re