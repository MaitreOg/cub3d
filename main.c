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
void	draw_cub_1(t_data *data, t_point *lst, int color)
{
	int	x;
	int	y;
	int	side;

	side = data->side;
	y = lst->y * side;
	while (y < lst->y * side + data->side)
	{
		x = lst->x * side;
		while (x < lst->x * side + data->side)
		{
			ft_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_cub_0(t_data *data, t_point *lst, int color)
{
	int	x;
	int	y;
	int	side;

	side = data->side;
	x = lst->x * side;
	y = lst->y * side;
	while (x < lst->x * side + data->side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x++;
	}
	while (y < lst->y * side + data->side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
	while (x > lst->x * side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x--;
	}
	while (y > lst->y * side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y--;
	}
}
void	draw_map(t_data *data)
{
	t_point	*tmp;

	tmp = data->map;
	while(tmp)
	{
		if (tmp->b == '1')
			draw_cub_1(data, tmp, 0xFFFFFF);
		else
			draw_cub_0(data, tmp, 0xFFFFFF);
		tmp = tmp->next;
	}
	create_player(data);
}
t_point *add_node(t_data *data, t_point *lst, int x, int y, char b)
{
	t_point *tmp;
	t_point *node;

	tmp = lst;
	node = malloc(sizeof(t_point));
	if (!node)
		return (NULL);
	if (b == 'N' || b == 'W' || b == 'S' || b == 'E')
	{
		data->corner = 0;
		data->player->x = x;
		data->player->y = y;
	}
	node->x = x;
	node->y = y;
	node->b = b;
	node->next = NULL;
	if (!tmp)
		return (node);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (lst);
}

void	create_map(t_data *data)
{
	int		fd;
	int	i;
	char	*line;
	int	y;

	y = 0;
	i = 0;
	fd = open("test_map.txt", 0);
	line = get_next_line(fd);
	data->map = malloc(sizeof(t_point *));
	data->map = NULL;
	data->player = malloc(sizeof(t_point));
	while (line)
	{
		i = -1;
		while(line[++i] && line[i] != '\n')
			data->map = add_node(data, data->map, i, y, line[i]);
		line = get_next_line(fd);
		y++;
	}
	get_next_line(-1);
	close (fd);
	draw_map(data);
}

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