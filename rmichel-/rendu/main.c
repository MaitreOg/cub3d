/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:32:24 by rmichel-          #+#    #+#             */
/*   Updated: 2024/07/31 17:43:47 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	create_win(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 480, "Cub3d");
	data.no = init_texture("src/north.xpm", data.mlx_ptr);
	data.so = init_texture("src/south.xpm", data.mlx_ptr);
	data.wo = init_texture("src/west.xpm", data.mlx_ptr);
	data.eo = init_texture("src/east.xpm", data.mlx_ptr);
	if (data.win_ptr == NULL)
		exit(1);
	pars(&data);
	raycast(&data, data.mlx_ptr, data.win_ptr);
	mlx_hook(data.win_ptr, 2, 1L << 0, &key_hook, &data);
	mlx_loop(data.mlx_ptr);
	exit(0);
}

int	main(void)
{
	create_win();
}
