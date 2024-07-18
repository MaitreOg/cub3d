/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:06:39 by smarty            #+#    #+#             */
/*   Updated: 2024/07/18 02:24:53 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	test_coord(int x, int y)
{
	if (x < 0 || y < 0 || x > 1920 || y > 1080)
		return (1);
	return (0);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (test_coord(x, y) == 0)
	{
		char	*dest;
		dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dest = color;
	}
}
void	draw_cub_1(t_data *data, int i, int color)
{
	int	x;
	int	y;

	y = data->map[i].y;
	while (y < data->map[i].y + data->side)
	{
		x = data->map[i].x;
		while (x < data->map[i].x + data->side)
		{
			ft_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	while (y < data->map[i].y + data->side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
}
void	draw_cub_0(t_data *data, int i, int color)
{
	int	x;
	int	y;

	x = data->map[i].x;
	y = data->map[i].y;
	while (x < data->map[i].x + data->side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x++;
	}
	while (y < data->map[i].y + data->side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
	while (x > data->map[i].x)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x--;
	}
	while (y > data->map[i].y)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y--;
	}
}
void	draw_map(t_data *data)
{
	int	i;

	i = 0;
	while(i < data->len)
	{
		if (data->map[i].b == 0)
			draw_cub_0(data, i, 0xFFFFFF);
		else
			draw_cub_1(data, i, 0xFFFFFF);

		i++;
	}
	create_player(data);
}
int add_node(char *line, t_data *data, int i, int y)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		data->map[i].x = x * data->side;
		data->map[i].y = y * data->side;
		data->map[i].b = line[x] - '0';
		//printf("x = %d       y = %d      b = %d\n", data->map[i].x, data->map[i].y, data->map[i].b);
		//printf ("[x = %d, y = %d, b = %d]", data->map[i].x, data->map[i].y, data->map[i].b);
		i++;
		x++;
	}
	data->len = i;
	draw_map(data);
	return (i);
}

void	create_player(t_data *data)
{
	ft_mlx_pixel_put(data, data->player->x, data->player->y, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x - 1, data->player->y, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x, data->player->y - 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x - 1, data->player->y - 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x + 1, data->player->y, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x, data->player->y + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x + 1 , data->player->y + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x - 1, data->player->y + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x + 1, data->player->y - 1, 0xFFF00F);
}

void	create_map(t_data *data)
{
	int		fd;
	int		i;
	char	*line;
	int		y;

	y = 0;
	i = 0;
	fd = open("test_map.txt", 0);
	line = get_next_line(fd);
	data->map = malloc(sizeof(t_point *));
	data->player = malloc(sizeof(t_point));
	while (line)
	{
		i += add_node(line, data, i, y);
		line = get_next_line(fd);
		y++;
	}
	get_next_line(-1);
	close (fd);
	data->player->x = 7 * data->side;
	data->player->y = 3 * data->side;
	create_player(data);
}

/*char **create_map(img)
{
	int		fd;
	int		i;
	char	**tab;
	char	*line;

	i = 0;
	fd = open("test_map.txt", 0);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i++;
	}
	map = malloc(sizeof(char *) * i + 1);
	close (fd);
	fd = open("test_map.txt", 0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		tab[i] = ft_strdup(line);
		printf("%s", tab[i]);
		line = get_next_line(fd);
		i++;
	}
	return (map);
}*/
void	start_value(t_data *data)
{
	data->side = 50;
}
void	create_win()
{
	t_data	*data;
	char	**map;

	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 900, 600, "Cub3d");
	if (data->win_ptr == NULL)
		exit(1);
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	start_value(data);
	create_map(data);
	(void)map;
	//img->len = len_map(tab);
	//draw_point(img);
	//free_tab(tab);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	mlx_hook(data->win_ptr, 2, 1L << 0, &key_hook, data);
	mlx_loop(data->mlx_ptr);
	exit(0);
}

int main()
{
	create_win();
}