/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:04:42 by rmichel-          #+#    #+#             */
/*   Updated: 2024/07/31 15:04:42 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	apply_texture(t_data *dt, t_img *texture, int y_img, int texc[])
{
	int	color;

	color = texture->data[texc[1] * TEX_WIDTH + texc[0]];
	dt->img.data[y_img * dt->img.width + dt->x] = color;
}

void	get_color_px2(int y, t_data *dt, int texc[])
{
	int	d;

	d = y * 256 - HEIGHT * 128 + dt->lineh * 128;
	texc[1] = ((d * TEX_HEIGHT) / dt->lineh) / 256;
	if (dt->side == 1)
	{
		if (dt->dir_ray.y < 0)
			apply_texture(dt, &dt->no, y, texc);
		else
			apply_texture(dt, &dt->so, y, texc);
	}
	else
	{
		if (dt->dir_ray.x < 0)
			apply_texture(dt, &dt->wo, y, texc);
		else
			apply_texture(dt, &dt->eo, y, texc);
	}
}

void	get_color_px(t_data *dt, t_img *img)
{
	float	wallx;
	int		texc[2];
	int		y;
	int		d;

	if (dt->side == 0)
		wallx = dt->player.y + dt->wall_dist * dt->dir_ray.y;
	else
		wallx = dt->player.x + dt->wall_dist * dt->dir_ray.x;
	wallx -= floorf(wallx);
	texc[0] = (int)(wallx * (float)TEX_WIDTH);
	if (dt->side == 0 && dt->dir_ray.x > 0)
		texc[0] = TEX_WIDTH - texc[0] - 1;
	if (dt->side == 1 && dt->dir_ray.y < 0)
		texc[0] = TEX_WIDTH - texc[0] - 1;
	y = dt->to_draw[0];
	while (y < dt->to_draw[1])
	{
		get_color_px2(y, dt, texc);
		y++;
	}
}

void	create_img(t_data *dt, t_img *img, void *mlx)
{
	get_color_px(dt, img);
}
