#include "cube3d.h"

void	draw_cub_1(t_data *data, int x, int y, int color)
{
	int	backup_x;
	int	backup_y;

	int	side;

	side = data->mul_side / 5;
	backup_x = x * side;
	backup_y = y * side;
	y = backup_y;
	while (y < backup_y + side)
	{
		x = backup_x;
		while (x < backup_x + side)
		{
			ft_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_cub_0(t_data *data, int x, int y, int color)
{
	int	side;
	int	backup_x;
	int	backup_y;

	side = data->mul_side / 5;
	backup_x = x * side;
	backup_y = y * side;
	x *= side;
	y *= side;
	while (x < backup_x + side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x++;
	}
	while (y < backup_y + side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y++;
	}
	while (x > backup_x)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x--;
	}
	while (y > backup_y)
	{
		ft_mlx_pixel_put(data, x, y, color);
		y--;
	}
}

void    draw_player(t_data *data)
{
    int s;
    s = data->mul_side / 5;
    ft_mlx_pixel_put(data, data->player.x * s, data->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s - 1, data->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s, data->player.y * s - 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s - 1, data->player.y * s - 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s + 1, data->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s, data->player.y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s + 1, data->player.y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s - 1, data->player.y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s + 1, data->player.y * s - 1, 0xFFF00F);
    ft_mlx_pixel_put(data, data->player.x * s, data->player.y * s - 2, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s, data->player.y * s + 2, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s - 2, data->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player.x * s + 2, data->player.y * s, 0xFFF00F);
}

void draw_view_minimap(t_data *data)
{
	
}
void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->mul_side = 50;
	while(data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_cub_1(data, x, y, 0xFFFFFF);
			else if (data->map[y][x] == '0')
				draw_cub_0(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	draw_player(data);
	draw_view_minimap(data);
}