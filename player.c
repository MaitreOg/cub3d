#include "cub3d.h"

t_point   find_b(t_data *data, t_point player)
{
	t_point *b;

	b = malloc(sizeof(t_point));
	b->x = player.x + 500;
	b->y = player.y;
	if (data->corner != 0)
		rotate_player(b, data->corner, player.x , player.y);
	return (*b);
}
int	find_block(t_data *data, t_point a)
{
	int	x;
	int	y;
	t_point *tmp;

	x = a.x / data->side;
	y = a.y / data->side;
	tmp = data->map;
	while(tmp)
	{
		if (tmp->x == x && tmp->y == y)
			break;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	if (tmp->b == '1')
		return  (1);
	return (0);
}
void	draw_ray(t_data *data, t_point a, t_point b)
{
	t_point	vector;
	t_point	pix;
	double	cd;
	int		i;

	i = 0;
	vector.x = (b.x - a.x);
	vector.y = (b.y - a.y);
	cd = fabs(vector.x) + fabs(vector.y);
	while (1)
	{
		pix.x = a.x + (vector.x * i) / cd;
		pix.y = a.y + (vector.y * i) / cd;
		if (find_block(data, pix) == 1)
			break ;
		ft_mlx_pixel_put(data, pix.x , pix.y, 0xFF00FF);
		i++;
	}
}
/*void	draw_ray(t_data *data, t_point a)
{
	t_point b;
	t_point	vector;
	t_point	pix;
	double	cd;
	int		i;

	i = 0;
	a.x *= data->side;
	a.y *= data->side;
	vector.x = (b.x - a.x);
	vector.y = (b.y - a.y);
	cd = fabs(vector.x) + fabs(vector.y);
	while (1)
	{
		pix.x = a.x + (vector.x * i) / cd;
		pix.y = a.y + (vector.y * i) / cd;
		if (find_block(data, pix) == 1)
			break ;
		ft_mlx_pixel_put(data, pix.x , pix.y, 0xFF00FF);
		i++;
	}
}
*/
void	compute_ray_pos(t_data *data, t_point a, t_point b, int i)
{
	t_point *c;

	c = malloc(sizeof(t_point));
	c->x = b.x;
	c->y = b.y;
	rotate_player(c, i * 0.01, a.x, a.y);
	draw_ray(data, a , *c);
	i++;
	if (i < 30)
		compute_ray_pos(data, a, b, i);
}

void	compute_ray_neg(t_data *data, t_point a, t_point b, int i)
{
	t_point *c;

	c = malloc(sizeof(t_point));
	c->x = b.x;
	c->y = b.y;
	rotate_player(c, i * 0.01, a.x, a.y);
	draw_ray(data, a , *c);
	i--;
	if (i > -30)
		compute_ray_neg(data, a, b, i);
}
void rotate_player(t_point *point, double corner, double center_x, double center_y)
{
	double  x;
	double  y;

	point->x -= center_x;
	point->y -= center_y;
	x = (point->x * cos(corner)) - (point->y * sin(corner));
	y = (point->x * sin(corner)) + (point->y * cos(corner));
	point->x = x + center_x;
	point->y = y + center_y;
}

void	create_player(t_data *data)
{
	int s;
	t_point a;
	s = data->side;
	a.x = data->player->x * s;
	a.y = data->player->y * s;
	compute_ray_pos(data, a, find_b(data, a), 0);
	compute_ray_neg(data, a, find_b(data, a), 0);
	ft_mlx_pixel_put(data, data->player->x * s, data->player->y * s, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s - 1, data->player->y * s, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s, data->player->y * s - 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s - 1, data->player->y * s - 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s + 1, data->player->y * s, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s, data->player->y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s + 1, data->player->y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s - 1, data->player->y * s + 1, 0xFF00FF);
	ft_mlx_pixel_put(data, data->player->x * s + 1, data->player->y * s - 1, 0xFFF00F);
}