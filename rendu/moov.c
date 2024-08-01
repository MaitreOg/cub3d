#include "cube3d.h"

int up_move(t_data *data)
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

int down_move(t_data *data)
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

int right_move(t_data *data)
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

int left_move(t_data *data)
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
