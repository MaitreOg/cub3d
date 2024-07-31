#include "cube3d.h"

void	init_player(t_data *data)
{

	data->player.x = 2;	
	data->player.y = 2;	
	
	data->corner = M_PI / 2;
    data->dir_cam.x = cos(data->corner);
    data->dir_cam.y = sin(data->corner);
    data->plane_cam.x = -sin(data->corner);
    data->plane_cam.y = cos(data->corner);
}

void	create_win()
{
	t_data	data;

	init_player(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 480, "Cub3d");
	data.NO = init_texture("src/north.xpm", data.mlx_ptr);
	data.SO = init_texture("src/south.xpm", data.mlx_ptr);
	data.WO = init_texture("src/west.xpm", data.mlx_ptr);
	data.EO = init_texture("src/east.xpm", data.mlx_ptr);
	if (data.win_ptr == NULL)
		exit(1);
    pars(&data);
    int y = -1;
    raycast(&data, data.mlx_ptr, data.win_ptr);
	mlx_hook(data.win_ptr, 2, 1L << 0, &key_hook, &data);
	mlx_loop(data.mlx_ptr);
	exit(0);   
}

int main(void)
{
    create_win();
}