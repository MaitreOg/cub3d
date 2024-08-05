/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:13:42 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/05 18:32:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	add_color(t_data *dt)
{
	int	x;

	x = -1;
	while (++x < WIDTH * HEIGHT / 2)
		dt->img.data[x] = dt->c;
	while (++x < WIDTH * HEIGHT)
		dt->img.data[x] = dt->f;
}

t_pos	calc_dir_ray(int x, t_pos dir, t_pos plane)
{
	float	cam_rel;
	t_pos	ray;
	float	xf;

	xf = (float)(x);
	cam_rel = 2 * xf / WF - 1.0;
	ray.x = dir.x + (plane.x * cam_rel);
	ray.y = dir.y + (plane.y * cam_rel);
	return (ray);
}

int	dda(t_data *dt)
{
	while (1)
	{
		if (dt->side_dist.x < dt->side_dist.y)
		{
			dt->side_dist.x += dt->delta.x;
			dt->floored.x += dt->step.x;
			dt->side = 0;
		}
		else
		{
			dt->side_dist.y += dt->delta.y;
			dt->floored.y += dt->step.y;
			dt->side = 1;
		}
		if (dt->map[(int)(dt->floored.y)][(int)(dt->floored.x)] == '1' || \
		dt->map[(int)(dt->floored.y)][(int)(dt->floored.x)] == '2')
		{
			if (dt->map[(int)(dt->floored.y)][(int)(dt->floored.x)] == '1')
				dt->info = 1;
			else
				dt->info = 3;
			break ;
		}
	}
	return (dt->side);
}

int	launch_ray(t_data *dt)
{
	dt->floored.x = (float)((int)(dt->player.x));
	dt->floored.y = (float)((int)(dt->player.y));
	dt->delta.x = absf(1 / dt->dir_ray.x);
	dt->delta.y = absf(1 / dt->dir_ray.y);
	dt->side_dist = init_side(dt->dir_ray, dt->player, dt->floored, dt->delta);
	dt->step = init_step(dt->dir_ray);
	dt->side = dda(dt);
	return (calc_height(dt));
}

void	raycast(t_data *dt, void *mlx, void *win)
{
	dt->img.width = WIDTH;
	dt->img.height = HEIGHT;
	dt->img.img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	dt->img.data = (int *)mlx_get_data_addr(dt->img.img_ptr, &dt->img.bpp, \
&dt->img.size_line, &dt->img.endian);
	add_color(dt);
	dt->x = 0;
	while (dt->x < WIDTH)
	{
		dt->dir_ray = calc_dir_ray(dt->x, dt->dir_cam, dt->plane_cam);
		dt->lineh = launch_ray(dt);
		dt->to_draw[0] = (-1 * dt->lineh) / 2 + HEIGHT / 2;
		if (dt->to_draw[0] < 0)
			dt->to_draw[0] = 0;
		dt->to_draw[1] = dt->lineh / 2 + HEIGHT / 2;
		if (dt->to_draw[1] >= HEIGHT)
			dt->to_draw[1] = HEIGHT;
		create_img(dt);
		dt->x += 1;
	}
	draw_minimap(dt);
	mlx_put_image_to_window(mlx, win, dt->img.img_ptr, 0, 0);
	mlx_destroy_image(mlx, dt->img.img_ptr);
}
