/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:21:24 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/06 11:03:33 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_img	init_texture(char *f, void *mlx)
{
	t_img	texture;

	texture.height = 100;
	texture.width = 100;
	if (open(f, O_RDONLY) == -1)
	{
		texture.img_ptr = NULL;
		texture.data = NULL;
		texture.init = -2;
		return (write(2, "Error\nTexture does not exist\n", 29), texture);
	}
	texture.img_ptr = mlx_xpm_file_to_image(mlx, f, &texture.width, \
&texture.height);
	texture.data = (int *)mlx_get_data_addr(texture.img_ptr, &texture.bpp, \
&texture.size_line, &texture.endian);
	texture.init = 0;
	return (texture);
}

t_pos	init_side(t_pos dir_ray, t_pos player, t_pos floored, t_pos delta)
{
	t_pos	side_dist;

	if (dir_ray.x < 0)
		side_dist.x = (player.x - floored.x) * delta.x;
	else
		side_dist.x = (floored.x + 1.0 - player.x) * delta.x;
	if (dir_ray.y < 0)
		side_dist.y = (player.y - floored.y) * delta.y;
	else
		side_dist.y = (floored.y + 1.0 - player.y) * delta.y;
	return (side_dist);
}

t_pos	init_step(t_pos dir_ray)
{
	t_pos	step;

	if (dir_ray.x < 0)
		step.x = -1.0;
	else
		step.x = 1.0;
	if (dir_ray.y < 0)
		step.y = -1.0;
	else
		step.y = 1.0;
	return (step);
}
