/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:04:42 by rmichel-          #+#    #+#             */
/*   Updated: 2024/07/31 15:04:42 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    detect_sprites(t_data *dt)
{
    int i;
    int j;
    int count;

    count = 0;
	i = -1;
    while (++i < dt->map_size[1])
	{
		j = -1;
        while (++j < dt->map_size[0])
		{
            if (dt->map[i][j] == 'P')
                count++;
		}
	}
    dt->sprites = malloc(sizeof(t_sprites) * count);
    dt->count = count;
    count = 0;
	i = -1;
    while (++i < dt->map_size[1])
	{
		j = -1;
        while (++j < dt->map_size[0])
		{
            if (dt->map[i][j] == 'P')
            {
                dt->sprites[count].x = j + 0.5;
                dt->sprites[count].y = i + 0.5;
                count++;
            }
		}
	}
}

void    sort_sprites(t_sprite *sprites, int count)
{
    int i;
    int j;
    t_sprite temp;

	i = -1;
    while (++i < count - 1)
    {
        while (++j < count - i - 1)
        {
            if (sprites[j].dist < sprites[j + 1].dist)
            {
                temp = sprites[j];
                sprites[j] = sprites[j + 1];
                sprites[j + 1] = temp;
            }
        }
    }
}

void    draw_sprites(t_data *dt, void *mlx, void *win)
{
    int i;

    // Calculer la distance des sprites
    for (i = 0; i < dt->num_sprites; i++)
    {
        dt->sprites[i].dist = ((dt->player.x - dt->sprites[i].x) * (dt->player.x - dt->sprites[i].x) +
                               (dt->player.y - dt->sprites[i].y) * (dt->player.y - dt->sprites[i].y));
    }

    // Trier les sprites par distance décroissante
    sort_sprites(dt->sprites, dt->num_sprites);

    // Dessiner chaque sprite
    for (i = 0; i < dt->num_sprites; i++)
    {
        // Calculer la position et la taille du sprite sur l'écran
        dt->sprite_coo.x = dt->sprites[i].x - dt->player.x;
        dt->sprite_coo.y = dt->sprites[i].y - dt->player.y;

        dt->inv = 1.0 / (dt->plane_cam.x * dt->dir_cam.y - dt->dir_cam.x * dt->plane_cam.y);

        dt->transform.x = dt->inv * (dt->dir_cam.y * dt->sprite_coo.x - dt->dir_cam.x * dt->sprite_coo.y);
        dt->transform.y = dt->inv * (-dt->plane_cam.y * dt->sprite_coo.x + dt->plane_cam.x * dt->sprite_coo.y);

        dt->sp_screen_x = (int)((WIDTH / 2) * (1 + dt->transform.x / transform.y));

        dt->sprite_h = abs((int)(HEIGHT / dt->transform.y));
        dt->to_drawy_sp[0] = -dt->sprite_h / 2 + HEIGHT / 2;
        if (dt->to_drawy_sp[0] < 0)
			dt->to_drawy_sp[0] = 0;
        dt->to_drawy_sp[1] = dt->sprite_h / 2 + HEIGHT / 2;
        if (dt->to_drawy_sp[1] >= HEIGHT)
			dt->to_drawy_sp[1] = HEIGHT - 1;

        dt->sprite_w = abs((int)(HEIGHT / dt->transform.y));
        dt->to_drawx_sp[0] = -dt->sprite_w / 2 + dt->sp_screen_x;
        if (dt->to_drawx_sp[0] < 0)
			dt->to_drawx_sp[0] = 0;
        dt->to_drawx_sp[1] = dt->sprite_w / 2 + dt->sp_screen_x;
        if (dt->to_drawx_sp[1] >= WIDTH)
			dt->to_drawx_sp[1] = WIDTH - 1;
        for (int stripe = dt->to_drawx_sp[0]; stripe < dt->to_drawx_sp[1]; stripe++)
        {
            int texX = (int)(256 * (stripe - (-dt->sprite_w / 2 + dt->sp_screen_x)) * TEX_WIDTH / dt->sprite_w) / 256;
            if (dt->transform.y > 0 && stripe > 0 && stripe < WIDTH && dt->transform.y < dt->zBuffer[stripe])
            {
                for (int y = dt->to_drawy_sp[0]; y < dt->to_drawy_sp[1]; y++)
                {
                    int d = (y) * 256 - HEIGHT * 128 + dt->sprite_h * 128;
                    int texY = ((d * TEX_HEIGHT) / dt->sprite_h) / 256;
                    int color = dt->sp.data[TEX_WIDTH * texY + texX];
                    if (color != 0) // Couleur différente du noir
                        dt->img.data[y * WIDTH + stripe] = color;
                }
            }
        }
    }
}