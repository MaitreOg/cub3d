/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:49:12 by marvin            #+#    #+#             */
/*   Updated: 2024/07/29 15:24:50 by marvin           ###   ########.fr       */
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
    printf("Hey cam_rel = %f", cam_rel);
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

int	dda(t_pos *side_dist, t_pos delta, t_pos *floored, t_pos *step)
{
    char	**map;
    int		side;

    map = handle_map('g', NULL);
    while (1)
    {
        if ((*side_dist).x < (*side_dist).y)
        {
            (*side_dist).x += delta.x;
            (*floored).x += (*step).x;
            side = 0;
        }
        else
        {
            (*side_dist).y += delta.y;
            (*floored).y += (*step).y;
            side = 1;
        }
        printf("Hey x = %d and y = %d\n", (int)((*floored).x), (int)((*floored).y));
        if (map[(int)((*floored).y)][(int)((*floored).x)] == '1')
        {
            //printf("Hey, c = %c", map[(int)(floored.y)][(int)(floored.x)]);
            break ;
        }
    }
    return (side);
}


int   launch_ray(t_pos player, t_pos dir_ray, t_pos *side_dist, int *side)
{
    t_pos	floored;
    t_pos	delta;
    t_pos	step;
    t_pos	vec[4];

    floored.x = (float)((int)(player.x));
    floored.y = (float)((int)(player.y));
    printf("Hoy: player.x = %f and floored.x = %f\n", player.x, floored.x);
    delta.x = absf(1/dir_ray.x);
    delta.y = absf(1/dir_ray.y);
    side_dist = init_side(dir_ray, player, floored, delta);
    step = init_step(dir_ray);
    *side = dda(side_dist, delta, &floored, &step);
    vec[0] = floored;
    vec[1] = delta;
    vec[2] = step;
    vec[3] = *side_dist;
    return (calc_height(vec, *side, player, dir_ray));
}

void	raycast(t_pos player, t_pos dir_cam, t_pos plane_cam, void *mlx, void *win)
{
    int		x;
    t_pos	dir_ray;
    int		wall;
    int		to_draw[2];
    void	*img;
    t_pos	side_dist;
    int		side;

    side_dist.x = 0.0;
    side_dist.y = 0.0;
    img = mlx_new_image(mlx, 640, 480);
    x = -1;
    while (++x < WIDTH)
    {
        printf("Hey x = %d\n", x);
        dir_ray = calc_dir_ray(x, dir_cam, plane_cam);
        wall = launch_ray(player, dir_ray, &side_dist, &side);
        printf("Hey wall = %d\n", wall);
        to_draw[0] = (-1 * wall) / 2 + HEIGHT / 2;
        if (to_draw[1] >= HEIGHT)
            to_draw[1] = HEIGHT;
        to_draw[1] = wall / 2 + HEIGHT / 2;
        if (to_draw[0] < 0)
            to_draw[0] = 0;
        printf("Hey td0 = %d and td1 = %d\n", to_draw[0], to_draw[1]);
        create_img(to_draw, x, &img, side_dist, side, mlx);
    }
    mlx_put_image_to_window(mlx, win, img, 0, 0);
}

int main(void)
{
    char **map;
    t_pos player;
    t_pos dir_cam;
    t_pos plane_cam;
    void *mlx;
    void *win;

    map = malloc(sizeof(char *) * 7);
    map[0] = "1111111111";
    map[1] = "101P010001";
    map[2] = "1000100101";
    map[3] = "1100000001";
    map[4] = "10010P0001";
    map[5] = "1111111111";
    map[6] = NULL;
    handle_map('p', map);
    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "Test");
    player.x = 2.2;
    player.y = 1.77;
    dir_cam.x = 0.707;
    dir_cam.y = 0.707;
    plane_cam.x = -0.707;
    plane_cam.y = 0.707;
    raycast(player, dir_cam, plane_cam, mlx, win);
    mlx_loop(mlx);
}
