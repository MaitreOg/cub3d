/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:32:24 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/06 15:22:40 by marvin           ###   ########.fr       */
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
	free_tab(dt->map);
	exit (EXIT_SUCCESS);
	return (0);
}

int	mouse_move_handler(int x, int y, t_data *data)
{
	(void)y;
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

void	init_keys(t_data *data)
{
	data->keys.backward = 0;
	data->keys.forward = 0;
	data->keys.move_right = 0;
	data->keys.move_left = 0;
	data->keys.rleft = 0;
	data->keys.rright = 0;
}

void	create_win(char **av)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Cub3d");
	init_keys(&data);
	init_all_tex(&data);
	if (data.win_ptr == NULL)
		exit(1);
	pars(&data, av);
	if (check_data_text(&data))
		return (write(2, "Error\nNot all texture set\n", 26), \
		key_destroyed(&data), exit(1));
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
		write(2, "Error\ninvalid argument\n", 23);
		return (0);
	}
	if (ft_strncmp(&(av[1][ft_strlen(av[1]) - 4]), ".cub", 2147483647))
		return (write(2, "Error\nfile not in .cub\n", 23), 1);
	create_win(av);
	return (0);
}
