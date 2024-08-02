/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:33:12 by smarty            #+#    #+#             */
/*   Updated: 2024/08/02 00:33:14 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	preset_door(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == '3')
				data->map[y][x] = '2';
		}
	}
}

void	manage_door(t_data *data, float x, float y)
{
	int	int_x;
	int	int_y;

	int_x = (int)floor(x);
	int_y = (int)floor(y);
	if (data->map[int_y][int_x] == '2')
	{
		data->map[int_y][int_x] = '3';
	}
	else if (data->map[int_y][int_x] == '3')
	{
		data->map[int_y][int_x] = '2';
	}
}

int	mouse_click_handler(int button, int x, int y, t_data *data)
{
	float	fx;
	float	fy;

	(void)x;
	(void)y;
	fx = data->player.x;
	fy = data->player.y;
	if (button == 1)
	{
		while (test_block(data, fx, fy) == 0)
		{
			fx += cos(data->corner);
			fy += sin(data->corner);
		}
		if (test_block(data, fx, fy) == 2 || test_block(data, fx, fy) == 3)
			manage_door(data, fx, fy);
	}
	return (0);
}
