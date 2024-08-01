#include "cube3d.h"

void preset_door(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while(data->map[++y])
	{
		x = -1;
		while(data->map[y][++x])
		{
			if (data->map[y][x] == '3')
				data->map[y][x] = '2';
		}
	}
}

int same_block(float xa, float ya, float xb, float yb)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;

	x1 = (int)floor(xa);
	y1 = (int)floor(ya);
	x2 = (int)floor(xb);
	y2 = (int)floor(yb);
	if (x1 == x2 && y1 == y2)
	{
		return (1);
	}
	return (0);

}

void	closing_door(t_data *data, float x, float y)
{
	int	int_x;
	int	int_y;

	int_x = (int)floor(x);
	int_y = (int)floor(y);
	if (same_block(data->player.x, data->player.y, x, y) == 0 && test_block(data, x, y) == 3)
		data->map[int_y][int_x] = '2';
}

void	open_door(t_data *data, float x, float y)
{
	int	int_x;
	int	int_y;

	int_x = (int)floor(x);
	int_y = (int)floor(y);
	if (same_block(data->player.x, data->player.y, x, y) == 0 && test_block(data, x, y) == 2)
	{
		data->map[int_y][int_x] = '3';
	}
}