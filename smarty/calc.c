#include "cube3d.h"

int calc_height(t_pos vec[], int side, t_pos player, t_pos dir_ray)
{
    float	wall_dist;
    int		lineh;

    if (side == 0)
        wall_dist = ((vec[0].x - player.x + (1.0 - vec[2].x) / 2.0) / dir_ray.x);
    else
        wall_dist = ((vec[0].y - player.y + (1.0 - vec[2].y) / 2.0) / dir_ray.y);
    //printf("Hey wall_dist = %f\n", wall_dist);
    lineh = (int)(HEIGHT/wall_dist);
    return (lineh);
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	result;
	int	signe;

	signe = 1;
	i = 0;
	result = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * signe);
}