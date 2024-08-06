/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:54:46 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/06 15:47:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_cub_1(t_data *data, int x, int y, int color)
{
	int	backup_x;
	int	backup_y;
	int	side;

	side = data->mul_side;
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

	side = data->mul_side;
	backup_x = x * side;
	backup_y = y * side;
	x *= side;
	y *= side;
	while (x < backup_x + side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		ft_mlx_pixel_put(data, x, y + side, color);
		x++;
	}
	while (y < backup_y + side)
	{
		ft_mlx_pixel_put(data, x, y, color);
		ft_mlx_pixel_put(data, x + side, y, color);
		y++;
	}
}

void	draw_player(t_data *dt)
{
	int	s;

	s = dt->mul_side;
	ft_mlx_pixel_put(dt, dt->player.x * s, dt->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s - 1, dt->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s, dt->player.y * s - 1, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s - 1, dt->player.y * s - 1, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s + 1, dt->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s, dt->player.y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s + 1, dt->player.y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s - 1, dt->player.y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s + 1, dt->player.y * s - 1, 0xFFF00F);
	ft_mlx_pixel_put(dt, dt->player.x * s, dt->player.y * s - 2, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s, dt->player.y * s + 2, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s - 2, dt->player.y * s, 0xFF00FF);
	ft_mlx_pixel_put(dt, dt->player.x * s + 2, dt->player.y * s, 0xFFF00F);
}

void	draw_view_minimap(t_data *data)
{
	int	begin_x;
	int	begin_y;
	int	i;

	begin_x = 0;
	begin_y = 0;
	i = 0;
	while (i < 10)
	{
		begin_x = cos(data->corner) * i;
		begin_y = sin(data->corner) * i;
		begin_x = (begin_x + data->player.x) * data->mul_side / 5;
		begin_x = (begin_y + data->player.y) * data->mul_side / 5;
		ft_mlx_pixel_put(data, begin_x, begin_y, 0x00FF00);
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->mul_side = WIDTH / (data->map_size[1] * 3);
	if (data->mul_side > HEIGHT / (data->map_size[1] * 3))
		data->mul_side = WIDTH / (data->map_size[0] * 3);
	while (data->map[y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '1')
				draw_cub_1(data, x, y, 0xFFFFFF);
			if (data->map[y][x] == '2')
				draw_cub_1(data, x, y, 0xAAAAAA);
			if (data->map[y][x] == '3')
				draw_cub_0(data, x, y, 0xAAAAAA);
			else if (data->map[y][x] == '0')
				draw_cub_0(data, x, y, 0xFFFFFF);
		}
		y++;
	}
	draw_player(data);
	draw_view_minimap(data);
}
