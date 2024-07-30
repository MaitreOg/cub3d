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

void	create_win(char **map)
{
	t_data	data;

	init_player(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 480, "Cub3d");
	if (data.win_ptr == NULL)
		exit(1);
	data.map = create_map(&data);
    int y = -1;
    printf("\n\ndata.map[0]: %s\n\n", data.map[0]); //, data.map[y + 1]);
    while (data.map[++y])
        printf("%s\n", data.map[y]);
	//img->len = len_map(tab);
    raycast(&data, data.mlx_ptr, data.win_ptr);
	//free_tab(tab);
	mlx_hook(data.win_ptr, 2, 1L << 0, &key_hook, &data);
	mlx_loop(data.mlx_ptr);
	exit(0);   
}

int main(void)
{
    char **map;
    t_pos player;
    t_pos dir_cam;
    t_pos plane_cam;
    t_data dt;
    map = malloc(sizeof(char *) * 7);
    map[0] = "1111111111";
    map[1] = "101P010001";
    map[2] = "1000100101";
    map[3] = "1100000001";
    map[4] = "10010P0001";
    map[5] = "1111111111";
    map[6] = NULL;
    create_win(map);
}