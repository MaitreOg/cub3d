/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:49:12 by marvin            #+#    #+#             */
/*   Updated: 2024/07/30 15:29:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_pos	calc_dir_ray(int x, t_pos dir, t_pos plane)
{
    float	cam_rel;
    t_pos	ray;
    float   xf;
    float   wf;

    xf = (float)(x);
    wf = (float)(WIDTH);
	cam_rel = 2 * xf / wf - 1.0;
    //printf("Hey cam_rel = %f", cam_rel);
    ray.x = dir.x + (plane.x * cam_rel);
    ray.y = dir.y + (plane.y * cam_rel);
    return (ray);
}

float	absf(float nb)
{
    if (nb < 0)
        nb *= (-1);
    return (nb);
}

int	dda(t_data *dt)
{
    char	**map;
    
    map = handle_map('g', NULL);
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
        //printf("Hey x = %d and y = %d\n", (int)(dt->floored.x), (int)(dt->floored.y));
        if (map[(int)(dt->floored.y)][(int)(dt->floored.x)] == '1')
        {
            ////printf("Hey, c = %c", map[(int)(floored.y)][(int)(floored.x)]);
            break ;
        }
    }
    return (dt->side);
}


int   launch_ray(t_data *dt)
{
    dt->floored.x = (float)((int)(dt->player.x));
    dt->floored.y = (float)((int)(dt->player.y));
    //printf("Hoy: player.x = %f and floored.x = %f\n", dt->player.x, dt->floored.x);
    dt->delta.x = absf(1/dt->dir_ray.x);
    dt->delta.y = absf(1/dt->dir_ray.y);
    dt->side_dist = init_side(dt->dir_ray, dt->player, dt->floored, dt->delta);
    dt->step = init_step(dt->dir_ray);
    dt->side = dda(dt);
    return (calc_height(dt));
}

void	raycast(t_data *dt, void *mlx, void *win)
{
    dt->img.width = WIDTH;
    dt->img.height = HEIGHT;
    dt->img.img_ptr = mlx_new_image(mlx, 640, 480);
    dt->img.data =  (int *)mlx_get_data_addr(dt->img.img_ptr, &dt->img.bpp, &dt->img.size_line, &dt->img.endian);
    dt->x = 0;
    while (dt->x < WIDTH)
    {
        //printf("Hey x = %d\n", dt->x);
        dt->dir_ray = calc_dir_ray(dt->x, dt->dir_cam, dt->plane_cam);
        dt->lineh = launch_ray(dt);
        //printf("Hey wall = %d\n", dt->lineh);
        dt->to_draw[0] = (-1 * dt->lineh) / 2 + HEIGHT / 2;
        if (dt->to_draw[0] < 0)
            dt->to_draw[0] = 0;
        dt->to_draw[1] = dt->lineh / 2 + HEIGHT / 2;
        if (dt->to_draw[1] >= HEIGHT)
            dt->to_draw[1] = HEIGHT;
        //printf("Hey td0 = %d and td1 = %d\n", dt->to_draw[0], dt->to_draw[1]);
        create_img(dt, &(dt->img), mlx);
        dt->x += 4;
    }
    mlx_put_image_to_window(mlx, win, dt->img.img_ptr, 0, 0);
    mlx_destroy_image(mlx, dt->img.img_ptr);
}

void	init_player(t_data *data)
{
	data->player.x = 3;	
	data->player.y = 3;	
	
	data->corner = M_PI / 2;
    data->dir_cam.x = cos(data->corner);
    data->dir_cam.y = sin(data->corner);
    data->plane_cam.x = -sin(data->corner);
    data->plane_cam.y = cos(data->corner);
}

void	create_win()
{
	t_data	data;
	char	**map;

	init_player(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 480, "Cub3d");
	if (data.win_ptr == NULL)
		exit(1);
	//create_map(data);
	(void)map;
	//img->len = len_map(tab);
    raycast(&data, data.mlx_ptr, data.win_ptr);
	//free_tab(tab);
	mlx_hook(data.win_ptr, 2, 1L << 0, &key_hook, &data);
	mlx_loop(data.mlx_ptr);
	exit(0);   
}
#include <unistd.h>

int main(void)
{
    char **map;
    t_pos player;
    t_pos dir_cam;
    t_pos plane_cam;
    t_data dt;
    map = malloc(sizeof(char *) * 7);
    map[0] = "1111111111";
    map[1] = "101P010001";
    map[2] = "1000100101";
    map[3] = "1100000001";
    map[4] = "10010P0001";
    map[5] = "1111111111";
    map[6] = NULL;
    handle_map('p', map);
    create_win();
/*/
    dt.mlx_ptr = mlx_init();
    dt.win_ptr = mlx_new_window(dt.mlx_ptr, 640, 480, "Test");
    dt.player.x = 2.2;
    dt.player.y = 1.77;
    dt.dir_cam.x = 0.707;
    dt.dir_cam.y = 0.707;
    dt.plane_cam.x = -0.707;
    dt.plane_cam.y = 0.850;
    raycast(&dt, dt.mlx_ptr, dt.win_ptr);
    //usleep(1000000);
    dt.dir_cam.x = -0.707;
    dt.dir_cam.y = 0.707;
    dt.plane_cam.x = -0.707;
    dt.plane_cam.y = -0.707;
    raycast(&dt, dt.mlx_ptr, dt.win_ptr);
    //usleep(1000000);
    dt.dir_cam.x = 0.707;
    dt.dir_cam.y = -0.707;
    dt.plane_cam.x = 0.707;
    dt.plane_cam.y = 0.707;
    raycast(&dt, dt.mlx_ptr, dt.win_ptr);
    mlx_loop(dt.mlx_ptr);*/
}
