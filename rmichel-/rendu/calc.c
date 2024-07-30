#include "cube3d.h"

int calc_height(t_data *dt)
{
    if (dt->side == 0)
        dt->wall_dist = ((dt->floored.x - dt->player.x + (1.0 - dt->step.x) / 2.0) / dt->dir_ray.x);
    else
        dt->wall_dist = ((dt->floored.y - dt->player.y + (1.0 - dt->step.y) / 2.0) / dt->dir_ray.y);
    //printf("Hey wall_dist = %f\n", dt->wall_dist);
    dt->lineh = (int)(HEIGHT/dt->wall_dist);
    return (dt->lineh);
}