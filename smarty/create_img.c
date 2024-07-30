
#include "cube3d.h"

int get_px_color(int td, char *file, t_pos side_dist, int side, void *mlx)
{
    int		column;
    void	*img;
    char	*adr;
    int		dt[4];

    img = mlx_xpm_file_to_image(mlx, file, 100, 100);
    adr = mlx_get_data_addr(img, &(dt[0]), &(dt[1]), &(dt[2]));
    if (side == 1)
        column = (int)((side_dist.y - (float)((int)side_dist.y)) * 100);
    else
        column = (int)((side_dist.x - (float)((int)side_dist.x)) * 100);
    dt[3] = (td * dt[1]) + (column * 4);
    if (dt[2] == 0)
        return (ft_atoi(adr[dt[3]]));
    else
        return (0xFFFFFF);
    
}

void create_img(int to_draw[], int x, t_data *data, t_pos side_dist, int side, void *mlx)
{
    static int color = 0xFFFFFF;
    int pixelc[2];
    int endian;
    char *buffer;

    data->addr = mlx_get_data_addr(data->img, &(pixelc[0]), &(pixelc[1]), &data->endian);
    while (to_draw[0] < to_draw[1])
    {
        int pixel = (to_draw[0] * pixelc[1]) + (x * 4);
        if (endian == 1)
        {
            data->addr[pixel + 0] = (color >> 24);
            data->addr[pixel + 1] = (color >> 16) & 0xFF;
            data->addr[pixel + 2] = (color >> 8) & 0xFF;
            data->addr[pixel + 3] = (color) & 0xFF;
        }
        else if (endian == 0)
        {
            data->addr[pixel + 0] = (color) & 0xFF;
            data->addr[pixel + 1] = (color >> 8) & 0xFF;
            data->addr[pixel + 2] = (color >> 16) & 0xFF;
            data->addr[pixel + 3] = (color >> 24);
        }
        data->addr[pixel] = color;
        (to_draw[0])++;
    }
}
