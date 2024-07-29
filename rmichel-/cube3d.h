#ifndef CUBE3D_H
# define CUBE3D_H

# define WIDTH 640
# define HEIGHT 480 
# define FOV 1.0472
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h> 
# include <stdio.h> 
typedef struct s_pos
{
    float	x;
    float	y;
} t_pos;

int calc_height(t_pos vec[], int side, t_pos player, t_pos dir_ray);
char	**handle_map(char c, char **map);
t_pos	init_side(t_pos dir_ray, t_pos player, t_pos floored, t_pos delta);
t_pos	init_step(t_pos dir_ray);
void create_img(int to_draw[], int x, void **img);

#endif
