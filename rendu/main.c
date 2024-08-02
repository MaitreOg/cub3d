/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:32:24 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/01 06:23:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	close_window(t_data *dt)
{
	mlx_destroy_image(dt->mlx_ptr, dt->no.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->so.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->eo.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->wo.img_ptr);
	mlx_destroy_image(dt->mlx_ptr, dt->d_o.img_ptr);
	mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	mlx_destroy_display(dt->mlx_ptr);
	free(dt->mlx_ptr);
	exit (EXIT_SUCCESS);
	return (0);
}

int	mouse_move_handler(int x, int y, t_data *data)
{
	if (x < data->x_mouse)
	{
		data->corner -= 0.03;
		data->dir_cam.x = cos(data->corner);
		data->dir_cam.y = sin(data->corner);
		data->plane_cam.x = -sin(data->corner);
		data->plane_cam.y = cos(data->corner);
		raycast(data, data->mlx_ptr, data->win_ptr);
	}
	else
	{
		data->corner += 0.03;
		data->dir_cam.x = cos(data->corner);
		data->dir_cam.y = sin(data->corner);
		data->plane_cam.x = -sin(data->corner);
		data->plane_cam.y = cos(data->corner);
		raycast(data, data->mlx_ptr, data->win_ptr);
	}
	data->x_mouse = x;
	return (0);
}

void	create_win(char **av)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 480, "Cub3d");
	data.keys.backward = 0;
	data.keys.forward = 0;
	data.keys.move_right = 0;
	data.keys.move_left = 0;
	data.keys.rleft = 0;
	data.keys.rright = 0;
	if (data.win_ptr == NULL)
		exit(1);
	pars(&data, av);
	raycast(&data, data.mlx_ptr, data.win_ptr);
	mlx_hook(data.win_ptr, 2, 1L << 0, &key_pressed, &data);
	mlx_hook(data.win_ptr, 3, 1L << 1, &key_release, &data);
	mlx_hook(data.win_ptr, 6, 1L << 6, &mouse_move_handler, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_window, &data);
	mlx_mouse_hook(data.win_ptr, mouse_click_handler, &data);
	mlx_loop_hook(data.mlx_ptr, update, &data);
	mlx_loop(data.mlx_ptr);
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("error\n");
		return (0);
	}
	create_win(av);
	return (0);
}
