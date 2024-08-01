#include "cube3d.h"

int	update2(t_data *data, int pressed)
{
	if (data->keys.forward == 1)
	{
		pressed++;
		if (pressed < 3 && up_move(data) == 0)
			forward(data);
	}
	if (data->keys.move_right == 1)
	{
		pressed++;
		if (pressed < 3 && right_move(data) == 0)
			mv_right(data);
	}
	if (data->keys.move_left == 1)
	{
		pressed++;
		if (pressed < 3 && left_move(data) == 0)
			mv_left(data);
	}
	if (data->keys.backward == 1)
	{
		pressed++;
		if (pressed < 3 && down_move(data) == 0)
			backward(data);
	}
}

int	update(t_data *data)
{
	int		pressed;

	pressed = 0;
	if (data->keys.rleft == 1)
	{
		if (pressed < 3)
		{
			pressed++;
			rleft(data);
		}
	}
	if (data->keys.rright == 1)
	{
		if (pressed < 3)
		{
			pressed++;
			rright(data);
		}
	}
	update2(data, pressed);
}

void	key_destroyed(t_data *dt)
{
	mlx_destroy_image(dt->mlx_ptr, dt->no.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->so.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->eo.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->wo.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->d_o.img_ptr);
	mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	mlx_destroy_display(dt->mlx_ptr);
	free(dt->mlx_ptr);
	free_tab(dt->map);
}

int	key_pressed(int keycode, t_data *dt)
{
	if (keycode == 65307)
	{
		key_destroyed(dt);
		exit (EXIT_SUCCESS);
	}
	if (keycode == 122 || keycode == 119)
		dt->keys.forward = 1;
	if (keycode == 100)
		dt->keys.move_right = 1;
	if (keycode == 97 || keycode == 113)
		dt->keys.move_left = 1;
	if (keycode == 115)
		dt->keys.backward = 1;
	if (keycode == 65361)
		dt->keys.rleft = 1;
	if (keycode == 65363)
		dt->keys.rright = 1;
	return (0);
}

int	key_release(int keycode, t_data *dt)
{
	if (keycode == 122 || keycode == 119)
		dt->keys.forward = 0;
	if (keycode == 100)
		dt->keys.move_right = 0;
	if (keycode == 97 || keycode == 113)
		dt->keys.move_left = 0;
	if (keycode == 115)
		dt->keys.backward = 0;
	if (keycode == 65361)
		dt->keys.rleft = 0;
	if (keycode == 65363)
		dt->keys.rright = 0;
	return (0);
}
