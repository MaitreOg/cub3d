/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:06:36 by smarty            #+#    #+#             */
/*   Updated: 2024/07/18 02:25:33 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct s_point{
	double	x;
	double	y;
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
	int		side;
	double	corner;
	t_point	*player;
	t_point	*map;
}				t_data;

//mlx function
int		key_hook(int keycode, t_data *img);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
char	*ft_strdup(char *s);
int		ft_atoi(char *nptr);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
//player function
void	create_player(t_data *data);
//map function
void	draw_map(t_data *data);
void 	rotate_player(t_point *point, double corner, double center_x, double center_y);
void	draw_ray(t_data *data, t_point a, t_point b);
t_point	find_b(t_data *data, t_point player);

#ifdef __linux__
# include <X11/keysym.h>
# include <X11/X.h>
#elif __APPLE__
# include <ApplicationServices/ApplicationServices.h>
#endif

#endif