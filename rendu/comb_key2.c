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
	float	x;
	float	y;

	x = data->player.x;
	y = data->player.y;
	data->player.x += cos(data->corner + M_PI / 2) * data->mv;
	data->player.y += sin(data->corner + M_PI / 2) * data->mv;
	closing_door(data, x, y);
	raycast(data, data->mlx_ptr, data->win_ptr);
}

void	mv_left(t_data *data)
{
	float	x;
	float	y;

	x = data->player.x;
	y = data->player.y;
	data->player.x += cos(data->corner - M_PI / 2) * data->mv;
	data->player.y += sin(data->corner - M_PI / 2) * data->mv;
	closing_door(data, x, y);
	raycast(data, data->mlx_ptr, data->win_ptr);
}

void	backward(t_data *data)
{
	float	x;
	float	y;

	x = data->player.x;
	y = data->player.y;
	data->player.x -= cos(data->corner) * data->mv;
	data->player.y -= sin(data->corner) * data->mv;
	closing_door(data, x, y);
	raycast(data, data->mlx_ptr, data->win_ptr);
}
