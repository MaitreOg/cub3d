/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:27:15 by rmichel-          #+#    #+#             */
/*   Updated: 2024/07/31 16:20:26 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	test_coord(int x, int y)
{
	if (x < 0 || y < 0 || x > 1920 || y > 1080)
		return (1);
	return (0);
}

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && x < data->img.width && y >= 0 && y < data->img.height)
	{
		dest = (char *)data->img.data + (y * data->img.size_line + x * \
		(data->img.bpp / 8));
		*(unsigned int *)dest = color;
	}
}

int	test_block(t_data *data, float backup_x, float backup_y)
{
	int	end_x;
	int	end_y;

	end_x = (int)floor(backup_x);
	end_y = (int)floor(backup_y);
	if (data->map[end_y][end_x] == '1' || !data->map[end_y][end_x])
		return (1);
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->no.img_ptr);
		mlx_destroy_image(data->mlx_ptr, data->so.img_ptr);
		mlx_destroy_image(data->mlx_ptr, data->eo.img_ptr);
		mlx_destroy_image(data->mlx_ptr, data->wo.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit (EXIT_SUCCESS);
	}
	else if (keycode == 122 || keycode == 119)
	{
		if (test_block(data, (data->player.x + cos(data->corner) * 0.05), \
		(data->player.y + sin(data->corner) * 0.05)) == 0)
		{
			data->player.x += cos(data->corner) * 0.05;
			data->player.y += sin(data->corner) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
	}
	else if (keycode == 100)
	{
		if (test_block(data, data->player.x + cos(data->corner + M_PI / 2) * \
		0.05, data->player.y + sin(data->corner + M_PI / 2) * 0.05) == 0)
		{
			data->player.x += cos(data->corner + M_PI / 2) * 0.05;
			data->player.y += sin(data->corner + M_PI / 2) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
	}
	else if (keycode == 97 || keycode == 113)
	{
		if (test_block(data, data->player.x + cos(data->corner - M_PI / 2) * \
		0.05, data->player.y + sin(data->corner - M_PI / 2) * 0.05) == 0)
		{
			data->player.x += cos(data->corner - M_PI / 2) * 0.05;
			data->player.y += sin(data->corner - M_PI / 2) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
	}
	else if (keycode == 115)
	{
		if (test_block(data, data->player.x - cos(data->corner) * 0.05, \
		data->player.y - sin(data->corner) * 0.05) == 0)
		{
			data->player.x -= cos(data->corner) * 0.05;
			data->player.y -= sin(data->corner) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
	}
	else if (keycode == 65361)
	{
		data->corner -= 0.05;
		data->dir_cam.x = cos(data->corner);
		data->dir_cam.y = sin(data->corner);
		data->plane_cam.x = -sin(data->corner);
		data->plane_cam.y = cos(data->corner);
		raycast(data, data->mlx_ptr, data->win_ptr);
	}
	else if (keycode == 65363)
	{
		data->corner += 0.05;
		data->dir_cam.x = cos(data->corner);
		data->dir_cam.y = sin(data->corner);
		data->plane_cam.x = -sin(data->corner);
		data->plane_cam.y = cos(data->corner);
		raycast(data, data->mlx_ptr, data->win_ptr);
	}
	return (0);
}
