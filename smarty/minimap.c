#include "cube3d.h"

void	draw_cub_1(t_data *data, t_point *lst, int color)
{
	int	x;
	int	y;
	int	side;

	side = data->mul_side / 5;
	y = lst->y * side;
	while (y < lst->y * side + data->mul_side / 5)
	{
		x = lst->x * side;
		while (x < lst->x * side + data->mul_side / 5)
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

	side = data->mul_side / 5;
	x = lst->x * side;
	y = lst->y * side;
	while (x < lst->x * side + data->mul_side / 5)
	{
		ft_mlx_pixel_put(data, x, y, color);
		x++;
	}
	while (y < lst->y * side + data->mul_side / 5)
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
void	draw_minimap(t_data *data)
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
}