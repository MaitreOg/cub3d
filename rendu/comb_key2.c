/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_key2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:33:05 by smarty            #+#    #+#             */
/*   Updated: 2024/08/05 18:39:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	rleft(t_data *data)
{
	data->corner -= 0.05;
	data->dir_cam.x = cos(data->corner);
	data->dir_cam.y = sin(data->corner);
	data->plane_cam.x = -sin(data->corner);
	data->plane_cam.y = cos(data->corner);
	raycast(data, data->mlx_ptr, data->win_ptr);
}

void	rright(t_data *data)
{
	data->corner += 0.05;
	data->dir_cam.x = cos(data->corner);
	data->dir_cam.y = sin(data->corner);
	data->plane_cam.x = -sin(data->corner);
	data->plane_cam.y = cos(data->corner);
	raycast(data, data->mlx_ptr, data->win_ptr);
}

void	mv_right(t_data *data)
{
	data->player.x += cos(data->corner + M_PI / 2) * data->mv;
	data->player.y += sin(data->corner + M_PI / 2) * data->mv;
	raycast(data, data->mlx_ptr, data->win_ptr);
}

void	mv_left(t_data *data)
{
	data->player.x += cos(data->corner - M_PI / 2) * data->mv;
	data->player.y += sin(data->corner - M_PI / 2) * data->mv;
	raycast(data, data->mlx_ptr, data->win_ptr);
}

void	backward(t_data *data)
{
	data->player.x -= cos(data->corner) * data->mv;
	data->player.y -= sin(data->corner) * data->mv;
	raycast(data, data->mlx_ptr, data->win_ptr);
}
