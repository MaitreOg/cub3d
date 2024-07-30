/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:06:32 by smarty            #+#    #+#             */
/*   Updated: 2024/07/30 16:56:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	test_coord(int x, int y)
{
	if (x < 0 || y < 0 || x > 1920 || y > 1080)
		return (1);
	return (0);
}
/*/
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (test_coord(x, y) == 0)
	{
		char	*dest;
		dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dest = color;
	}
}*/
int	test_block(t_data *data, int x, int y)
{
	t_point *tmp;
	tmp = data->map;
	while(tmp)
	{
		if (tmp->x == x && tmp->y == y)
			break;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	if (tmp->b == '1')
		return  (1);
	return (0);
}
/*
void	recovery(t_data *map)
{
	int i;
	int y;

	y = 0;
	while (y < 480)
	{
		i = 0;
		while (i < 640)
		{
			ft_mlx_pixel_put(map, i, y, 0x00000000);
			i++;
		}
		y++;
	}
}*/

int	key_hook(int keycode, t_data *data)
{
	//printf("corner = %f\n", data->corner);
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free (data);
		exit (EXIT_SUCCESS);
    }
	else if (keycode == 122)
	{
		//recovery(data);
		//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->player.x += cos(data->corner) * 0.05;
		data->player.y += sin(data->corner) * 0.05;
		raycast(data, data->mlx_ptr, data->win_ptr);
    	//printf("cos(corner) = %f\tsin(corner) = %f\n", cos(data->corner) / 2, sin(data->corner) / 2);
		//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 100)
	{
		//recovery(data);
		//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->player.x += cos(data->corner + M_PI / 2) * 0.05;
		data->player.y += sin(data->corner + M_PI / 2) * 0.05;
		raycast(data, data->mlx_ptr, data->win_ptr);
		//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 113)
	{
		//recovery(data);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->player.x += cos(data->corner - M_PI / 2) * 0.05;
		data->player.y += sin(data->corner - M_PI / 2) * 0.05;
		raycast(data, data->mlx_ptr, data->win_ptr);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 115)
	{
	//	recovery(data);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->player.x -= cos(data->corner) * 0.05;
		data->player.y -= sin(data->corner) * 0.05;
		raycast(data, data->mlx_ptr, data->win_ptr);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 65361)
	{
	//	recovery(data);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->corner -= 0.05;
    	data->dir_cam.x = cos(data->corner);
    	data->dir_cam.y = sin(data->corner);
    	data->plane_cam.x = -sin(data->corner);
    	data->plane_cam.y = cos(data->corner);
		raycast(data, data->mlx_ptr, data->win_ptr);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 65363)
	{
	//	recovery(data);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->corner += 0.05;
    	data->dir_cam.x = cos(data->corner);
    	data->dir_cam.y = sin(data->corner);
    	data->plane_cam.x = -sin(data->corner);
    	data->plane_cam.y = cos(data->corner);
		raycast(data, data->mlx_ptr, data->win_ptr);
	//	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
   // printf("player.x  = %f\tplayer.y =  %f\n", data->player.x, data->player.y);
	//printf("keycode = %d\n\n\n\n", keycode);
	return (0);
}