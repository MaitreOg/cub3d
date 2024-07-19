/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:06:32 by smarty            #+#    #+#             */
/*   Updated: 2024/07/18 02:25:16 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	recovery(t_data *map)
{
	int i;
	int y;

	y = 0;
	while (y < 1080)
	{
		i = 0;
		while (i < 1920)
		{
			ft_mlx_pixel_put(map, i, y, 0x00000000);
			i++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free (data->map);
		free(data->mlx_ptr);
		free (data);
		exit (EXIT_SUCCESS);
    }
	else if (keycode == 115)
	{
		recovery(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		if (test_block(data, data->player->x, data->player->y + 0.1) == 0)
				data->player->y += 0.1;
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 113)
	{
		recovery(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		if (test_block(data, data->player->x - 0.1, data->player->y) == 0)
			data->player->x -= 0.1;
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 100)
	{
		recovery(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		if (test_block(data, data->player->x + 0.1, data->player->y) == 0)
		data->player->x += 0.1;
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 122)
	{
		recovery(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		if (test_block(data, data->player->x, data->player->y - 0.1) == 0)
			data->player->y -= 0.1;
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 65361)
	{
		recovery(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->corner -= 0.05;
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
	else if (keycode == 65363)
	{
		recovery(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
		data->corner += 0.05;
		draw_map(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	}
    //printf("%d\n", keycode);
	return (0);
}