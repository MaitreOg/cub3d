
#include "cube3d.h"
void create_img(int to_draw[], int x, void **img)
{
    static int color = 0xFFFFFF;
    int pixelc[2];
    int endian;
    char *buffer;

    buffer = mlx_get_data_addr(*img, &(pixelc[0]), &(pixelc[1]), &endian);
    while (to_draw[0] < to_draw[1])
    {
        int pixel = (to_draw[0] * pixelc[1]) + (x * 4);
        if (endian == 1)
        {
            buffer[pixel + 0] = (color >> 24);
            buffer[pixel + 1] = (color >> 16) & 0xFF;
            buffer[pixel + 2] = (color >> 8) & 0xFF;
            buffer[pixel + 3] = (color) & 0xFF;
        }
        else if (endian == 0)
        {
            buffer[pixel + 0] = (color) & 0xFF;
            buffer[pixel + 1] = (color >> 8) & 0xFF;
            buffer[pixel + 2] = (color >> 16) & 0xFF;
            buffer[pixel + 3] = (color >> 24);
        }
            buffer[pixel] = color;
            (to_draw[0])++;
    }
}
