/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:33:56 by smarty            #+#    #+#             */
/*   Updated: 2024/08/02 00:33:57 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	up_move(t_data *data)
{
	float	add_x;
	float	add_y;
	float	x;
	float	y;

	add_x = 0.02;
	add_y = 0.02;
	x = data->player.x + cos(data->corner) * data->mv;
	y = data->player.y + sin(data->corner) * data->mv;
	if (test_block(data, x, y) == 2)
		open_door(data, x, y);
	else if (test_block(data, x, y) == 1)
		return (1);
	if (test_block(data, x + add_x, y) == 1)
		return (1);
	if (test_block(data, x, y + add_y) == 1)
		return (1);
	if (test_block(data, x - add_x, y) == 1)
		return (1);
	if (test_block(data, x, y - add_y) == 1)
		return (1);
	return (0);
}

int	down_move(t_data *data)
{
	float	add_x;
	float	add_y;
	float	x;
	float	y;

	add_x = 0.02;
	add_y = 0.02;
	x = data->player.x - cos(data->corner) * data->mv * 4;
	y = data->player.y - sin(data->corner) * data->mv * 4;
	if (test_block(data, x, y) == 2)
		open_door(data, x, y);
	if (test_block(data, x, y) == 1)
		return (1);
	if (test_block(data, x + add_x, y) == 1)
		return (1);
	if (test_block(data, x, y + add_y) == 1)
		return (1);
	if (test_block(data, x - add_x, y) == 1)
		return (1);
	if (test_block(data, x, y - add_y) == 1)
		return (1);
	return (0);
}

int	right_move(t_data *data)
{
	float	add_x;
	float	add_y;
	float	x;
	float	y;

	add_x = 0.02;
	add_y = 0.02;
	x = data->player.x + cos(data->corner + M_PI / 2) * data->mv;
	y = data->player.y + sin(data->corner + M_PI / 2) * data->mv;
	if (test_block(data, x, y) == 2)
		open_door(data, x, y);
	if (test_block(data, x, y) == 1)
		return (1);
	if (test_block(data, x + add_x, y) == 1)
		return (1);
	if (test_block(data, x, y + add_y) == 1)
		return (1);
	if (test_block(data, x - add_x, y) == 1)
		return (1);
	if (test_block(data, x, y - add_y) == 1)
		return (1);
	return (0);
}

int	left_move(t_data *data)
{
	float	add_x;
	float	add_y;
	float	x;
	float	y;

	add_x = 0.02;
	add_y = 0.02;
	x = data->player.x + cos(data->corner + M_PI / 2) * data->mv;
	y = data->player.y + sin(data->corner + M_PI / 2) * data->mv;
	if (test_block(data, x, y) == 2)
		open_door(data, x, y);
	if (test_block(data, x, y) == 1)
		return (1);
	if (test_block(data, x + add_x, y) == 1)
		return (1);
	if (test_block(data, x, y + add_y) == 1)
		return (1);
	if (test_block(data, x - add_x, y) == 1)
		return (1);
	if (test_block(data, x, y - add_y) == 1)
		return (1);
	return (0);
}

void	forward(t_data *data)
{
	float	x;
	float	y;

	x = data->player.x;
	y = data->player.y;
	data->player.x += cos(data->corner) * data->mv;
	data->player.y += sin(data->corner) * data->mv;
	closing_door(data, x, y);
	raycast(data, data->mlx_ptr, data->win_ptr);
}
