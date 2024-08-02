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
	float	ax;
	float	ay;
	float	x;
	float	y;

	ax = 0.02;
	ay = 0.02;
	x = data->player.x + cos(data->corner) * data->mv;
	y = data->player.y + sin(data->corner) * data->mv;
	if (test_block(data, x, y) == 1 || test_block(data, x, y) == 2)
		return (1);
	if (test_block(data, x + ax, y) == 1 || test_block(data, x + ax, y) == 2)
		return (1);
	if (test_block(data, x, y + ay) == 1 || test_block(data, x, y + ay) == 2)
		return (1);
	if (test_block(data, x - ax, y) == 1 || test_block(data, x - ax, y) == 2)
		return (1);
	if (test_block(data, x, y - ay) == 1 || test_block(data, x, y - ay) == 2)
		return (1);
	return (0);
}

int	down_move(t_data *data)
{
	float	ax;
	float	ay;
	float	x;
	float	y;

	ax = 0.02;
	ay = 0.02;
	x = data->player.x - cos(data->corner) * data->mv * 4;
	y = data->player.y - sin(data->corner) * data->mv * 4;
	if (test_block(data, x, y) == 1 || test_block(data, x, y) == 2)
		return (1);
	if (test_block(data, x + ax, y) == 1 || test_block(data, x + ax, y) == 2)
		return (1);
	if (test_block(data, x, y + ay) == 1 || test_block(data, x, y + ay) == 2)
		return (1);
	if (test_block(data, x - ax, y) == 1 || test_block(data, x - ax, y) == 2)
		return (1);
	if (test_block(data, x, y - ay) == 1 || test_block(data, x, y - ay) == 2)
		return (1);
	return (0);
}

int	right_move(t_data *data)
{
	float	ax;
	float	ay;
	float	x;
	float	y;

	ax = 0.02;
	ay = 0.02;
	x = data->player.x + cos(data->corner + M_PI / 2) * data->mv;
	y = data->player.y + sin(data->corner + M_PI / 2) * data->mv;
	if (test_block(data, x, y) == 1 || test_block(data, x, y) == 2)
		return (1);
	if (test_block(data, x + ax, y) == 1 || test_block(data, x + ax, y) == 2)
		return (1);
	if (test_block(data, x, y + ay) == 1 || test_block(data, x, y + ay) == 2)
		return (1);
	if (test_block(data, x - ax, y) == 1 || test_block(data, x - ax, y) == 2)
		return (1);
	if (test_block(data, x, y - ay) == 1 || test_block(data, x, y - ay) == 2)
		return (1);
	return (0);
}

int	left_move(t_data *data)
{
	float	ax;
	float	ay;
	float	x;
	float	y;

	ax = 0.02;
	ay = 0.02;
	x = data->player.x + cos(data->corner - M_PI / 2) * data->mv;
	y = data->player.y + sin(data->corner - M_PI / 2) * data->mv;
	if (test_block(data, x, y) == 1 || test_block(data, x, y) == 2)
		return (1);
	if (test_block(data, x + ax, y) == 1 || test_block(data, x + ax, y) == 2)
		return (1);
	if (test_block(data, x, y + ay) == 1 || test_block(data, x, y + ay) == 2)
		return (1);
	if (test_block(data, x - ax, y) == 1 || test_block(data, x - ax, y) == 2)
		return (1);
	if (test_block(data, x, y - ay) == 1 || test_block(data, x, y - ay) == 2)
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
	raycast(data, data->mlx_ptr, data->win_ptr);
}
