#include "cube3d.h"

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
	t_data	*data;
	char	**map;

    
	data = malloc(sizeof(t_data));
	init_player(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 640, 480, "Cub3d");
	if (data->win_ptr == NULL)
		exit(1);
	data->img = mlx_new_image(data->mlx_ptr, 640, 480);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	//create_map(data);
	(void)map;
	//img->len = len_map(tab);
    raycast(data);
	//free_tab(tab);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img , 0, 0);
	mlx_hook(data->win_ptr, 2, 1L << 0, &key_hook, data);
	mlx_loop(data->mlx_ptr);
	exit(0);
    
}

int main()
{
    char **map;

    map = malloc(sizeof(char *) * 7);
    map[0] = "1111111111";
    map[1] = "1000000001";
    map[2] = "1110000001";
    map[3] = "1000001101";
    map[4] = "1010000001";
    map[5] = "1111111111";
    map[6] = NULL;
    handle_map('p', map);
	create_win();
}