/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:21:45 by rmichel-          #+#    #+#             */
/*   Updated: 2024/07/31 16:21:45 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define FRAME (1000000 / 60)
# define WIDTH 640
# define WF 640.0
# define HEIGHT 480 
# define H2 240
# define FOV 1.0472
# define TEX_WIDTH 100
# define TEX_HEIGHT 100

# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdlib.h> 
# include <stdio.h> 
# include <fcntl.h>

typedef struct s_key
{
	int	forward;
	int	backward;
	int	move_left;
	int	move_right;
	int	rleft;
	int	rright;
}	t_key;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_pos
{
	float	x;
	float	y;
}	t_pos;

typedef struct s_point
{
	float			x;
	float			y;
	char			b;
	struct s_point	*next;
}			t_point;

typedef struct s_data
{
//	mlx var
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_img	img;
	struct s_key	keys;
//	preset var
	int				info;
	int				mul_side;
	float			corner;
	t_pos			side_dist;
	t_pos			dir_ray;
	int				side;
	t_pos			player;
	t_pos			dir_cam;
	t_pos			plane_cam;
	int				to_draw[2];
	int				wall;
	t_pos			floored;
	t_pos			delta;
	t_pos			step;
	float			wall_dist;
	int				lineh;
	int				x;
	char			**map;
	float			mv;
	int				x_mouse;
//texture
	t_img			no;
	t_img			so;
	t_img			wo;
	t_img			eo;
	t_img			d_o;
	int				c;
	int				f;

}				t_data;

t_img	init_texture(char *f, void *mlx);
float	absf(float nb);
int		calc_height(t_data *dt);
char	**handle_map(char c, char **map);
t_pos	init_side(t_pos dir_ray, t_pos player, t_pos floored, t_pos delta);
t_pos	init_step(t_pos dir_ray);
void	create_img(t_data *dt, t_img *img, void *mlx);
int		key_hook(int keycode, t_data *data);
void	raycast(t_data *dt, void *mlx, void *win);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
char	**create_map(t_data *data, char **parsing, int i);
void	draw_minimap(t_data *data);
char	*ft_strdup(char *str);
void	pars(t_data *data, char **av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char *s, char c);
char	*ft_strjoin_cub(char *s1, char *s2, int a, int b);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *pt, size_t n);
char	*ft_strdup(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *pt, int c, size_t n);
void	ft_free(char **tab);
void	init_player(t_data *data, int x, int y, char c);
int		update(t_data *data);
int		key_pressed(int keycode, t_data *dt);
int		key_release(int keycode, t_data *dt);
int		test_block(t_data *data, float backup_x, float backup_y);
int		up_move(t_data *data);
int		down_move(t_data *data);
int		left_move(t_data *data);
int		right_move(t_data *data);
void	preset_door(t_data *data);
int		test_block(t_data *data, float backup_x, float backup_y);
void	free_tab(char **tab);
int		ft_atoi(const char *nbr);
void	forward(t_data *data);
void	rleft(t_data *data);
void	rright(t_data *data);
void	mv_right(t_data *data);
void	mv_left(t_data *data);
void	backward(t_data *data);
int		init_color(t_data *dt, char *str);
void	param_texture(t_data *data, t_img texture, char *texture_path);
void	keep_texture(t_data *data, char *str);
int		skip_line(char *str);
void	key_destroyed(t_data *dt);
int		mouse_click_handler(int button, int x, int y, t_data *data);

#endif
