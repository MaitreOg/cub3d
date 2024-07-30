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
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
//	preset var
	int 	mul_side;
	float	corner;
    t_pos   dir_cam;
    t_pos   plane_cam;
	t_pos   player;
	t_point	*map;
}				t_data;

int	key_hook(int keycode, t_data *data);
int     calc_height(t_pos vec[], int side, t_pos player, t_pos dir_ray);
char	**handle_map(char c, char **map);
t_pos	init_side(t_pos dir_ray, t_pos player, t_pos floored, t_pos delta);
t_pos	init_step(t_pos dir_ray);
void    create_img(int to_draw[], int x, t_data *data, t_pos side_dist, int side, void *mlx);
int	    ft_atoi(char *nptr);
void	raycast(t_data *data);
void	draw_minimap(t_data *data);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
