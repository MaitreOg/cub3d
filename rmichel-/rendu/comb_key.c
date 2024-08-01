#include "cube3d.h"

int update(t_data *data)
{
    int pressed;

    pressed = 0;
    if (data->keys.rleft == 1)
    {
        if (pressed < 3)
        {
            pressed++;
		    data->corner -= 0.05;
    		data->dir_cam.x = cos(data->corner);
	    	data->dir_cam.y = sin(data->corner);
		    data->plane_cam.x = -sin(data->corner);
    		data->plane_cam.y = cos(data->corner);
	    	raycast(data, data->mlx_ptr, data->win_ptr);
        }
	}
    if (data->keys.rright == 1)
    {
        if (pressed < 3)
        {
            pressed++;
	    	data->corner += 0.05;
		    data->dir_cam.x = cos(data->corner);
    		data->dir_cam.y = sin(data->corner);
	    	data->plane_cam.x = -sin(data->corner);
		    data->plane_cam.y = cos(data->corner);
    		raycast(data, data->mlx_ptr, data->win_ptr);
        }
	}
    if (data->keys.forward == 1)
    {
        pressed++;
        if (pressed < 3 && test_block(data, (data->player.x + cos(data->corner) * 0.05), \
		(data->player.y + sin(data->corner) * 0.05)) == 0)
		{
			data->player.x += cos(data->corner) * 0.05;
			data->player.y += sin(data->corner) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
    }
    if (data->keys.move_right == 1)
    {
        pressed++;
        if (pressed < 3 && test_block(data, data->player.x + cos(data->corner + M_PI / 2) * \
		0.05, data->player.y + sin(data->corner + M_PI / 2) * 0.05) == 0)
		{
			data->player.x += cos(data->corner + M_PI / 2) * 0.05;
			data->player.y += sin(data->corner + M_PI / 2) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
    }
    if (data->keys.move_left == 1)
    {
        pressed++;
		if (pressed < 3 && test_block(data, data->player.x + cos(data->corner - M_PI / 2) * \
		0.05, data->player.y + sin(data->corner - M_PI / 2) * 0.05) == 0)
		{
			data->player.x += cos(data->corner - M_PI / 2) * 0.05;
			data->player.y += sin(data->corner - M_PI / 2) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
	}
    if (data->keys.backward == 1)
    {
        pressed++;
		if (pressed < 3 && test_block(data, data->player.x - cos(data->corner) * 0.05, \
		data->player.y - sin(data->corner) * 0.05) == 0)
		{
			data->player.x -= cos(data->corner) * 0.05;
			data->player.y -= sin(data->corner) * 0.05;
			raycast(data, data->mlx_ptr, data->win_ptr);
		}
	}
}

int key_pressed(int keycode, t_data *dt)
{
    printf("pressed: %d\n", keycode);
    if (keycode == 65307)
	{
		mlx_destroy_image(dt->mlx_ptr, dt->no.img_ptr);
		mlx_destroy_image(dt->mlx_ptr, dt->so.img_ptr);
		mlx_destroy_image(dt->mlx_ptr, dt->eo.img_ptr);
		mlx_destroy_image(dt->mlx_ptr, dt->wo.img_ptr);
		mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
		mlx_destroy_display(dt->mlx_ptr);
		free(dt->mlx_ptr);
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
    printf("pressed: %d\npressed: %d\n", dt->keys.rright, dt->keys.rleft);
    return (0);
}

int key_release(int keycode, t_data *dt)
{
    printf("released: %d", keycode);
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
    printf("released: %d : %d\n", keycode, dt->keys.rleft);
    return (0);
}
