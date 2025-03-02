#ifndef CUBE3D_H
# define CUBE3D_H

# define WIDTH 640
# define HEIGHT 480 
# define FOV 1.0472
# define TEX_WIDTH 100
# define TEX_HEIGHT 100

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h> 
# include <stdio.h> 

typedef struct s_img
{
    void *img_ptr;
    int *data;
    int bpp;
    int size_line;
    int endian;
    int width;
    int height;
} t_img;

typedef struct s_pos
{
    float	x;
    float	y;
} t_pos;
/*
typedef struct s_math_dt
{
    t_pos	side_dist;
    t_pos	dir_ray;
    int		side;
    t_pos player;
    t_pos dir_cam;
    t_pos plane_cam;
    int		to_draw[2];
    int		wall;
    t_pos	floored;
    t_pos	delta;
    t_pos	step;
    float	wall_dist;
    int		lineh;
    int     x;
} t_math_dt; */

typedef struct s_point{
	float	x;
	float	y;
	char	b;
	struct s_point *next;
}			t_point;

typedef struct	s_data {
//	mlx var
	void 	*mlx_ptr;
	void	*win_ptr;
	struct  s_img img;
//	preset var
	int 	mul_side;
	float	corner;
    t_pos	side_dist;
    t_pos	dir_ray;
    int		side;
    t_pos player;
    t_pos dir_cam;
    t_pos plane_cam;
    int		to_draw[2];
    int		wall;
    t_pos	floored;
    t_pos	delta;
    t_pos	step;
    float	wall_dist;
    int		lineh;
    int     x;
	t_point	*map;
}				t_data;

int calc_height(t_data *dt);
char	**handle_map(char c, char **map);
t_pos	init_side(t_pos dir_ray, t_pos player, t_pos floored, t_pos delta);
t_pos	init_step(t_pos dir_ray);
void create_img(t_data *dt, t_img  *img, void *mlx);
int	key_hook(int keycode, t_data *data);
void	raycast(t_data *dt, void *mlx, void *win);
float	absf(float nb);

#endif
