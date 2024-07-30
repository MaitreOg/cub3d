
#include "cube3d.h"

void apply_texture(t_img *img, t_img *texture, int x_img, int y_img, int x_tex, int y_tex)
{
    int color = texture->data[y_tex * TEX_WIDTH + x_tex];
    if (img->data[y_img * img->width + x_img] != color)
        img->data[y_img * img->width + x_img] = color;
}

void get_color_px(t_math_dt *dt, t_img *img, t_img texture[])
{
    float wallx;
    int texx;
    int texy;
    int y;
    int d;

    if (dt->side == 0)
        wallx = dt->player.y + dt->wall_dist * dt->dir_ray.y;
    else
        wallx = dt->player.x + dt->wall_dist * dt->dir_ray.x;
    wallx -= floorf(wallx);
    texx = (int)(wallx * (float)TEX_WIDTH);
    if (dt->side == 0 && dt->dir_ray.x > 0)
        texx = TEX_WIDTH - texx - 1;
    if (dt->side == 1 && dt->dir_ray.y < 0)
        texx = TEX_WIDTH - texx - 1;
    y = dt->to_draw[0];
    while (y < dt->to_draw[1])
    {
        d = y * 256 - HEIGHT * 128 + dt->lineh * 128;
        texy = ((d * TEX_HEIGHT) / dt->lineh) / 256;
        if (dt->dir_cam.y < 0)
        {
            if (dt->side == 0)
                apply_texture(img, &texture[0], dt->x, y, texx, texy);
            else
            {
                if (atan2f(dt->dir_cam.x, dt->dir_cam.y) < 1.5708)
                    apply_texture(img, &texture[3], dt->x, y, texx, texy);
                else
                    apply_texture(img, &texture[2], dt->x, y, texx, texy);
            }
        }
        else
        {
            if (dt->side == 0)
                apply_texture(img, &texture[1], dt->x, y, texx, texy);
            else
            {
                if (atan2f(dt->dir_cam.x, dt->dir_cam.y) < 1.5708)
                    apply_texture(img, &texture[2], dt->x, y, texx, texy);
                else
                    apply_texture(img, &texture[3], dt->x, y, texx, texy);
            }
        }
        y++;
    }
}

void create_img(t_math_dt *dt, t_img  *img, void *mlx)
{
    static int color = 0xFFFFFF;
    t_img   texture[4];

    texture[0].height = 100;
    texture[0].width = 100;
    texture[0].img_ptr = mlx_xpm_file_to_image(mlx, "src/north.xpm", &texture[0].width, &texture[0].height);
    texture[0].data = (int *)mlx_get_data_addr(texture[0].img_ptr, &texture[0].bpp, &texture[0].size_line, &texture[0].endian);
    texture[1].height = 100;
    texture[1].width = 100;
    texture[1].img_ptr = mlx_xpm_file_to_image(mlx, "src/south.xpm", &texture[1].width, &texture[1].height);
    texture[1].data = (int *)mlx_get_data_addr(texture[1].img_ptr, &texture[1].bpp, &texture[1].size_line, &texture[1].endian);
    texture[2].height = 100;
    texture[2].width = 100;
    texture[2].img_ptr = mlx_xpm_file_to_image(mlx, "src/east.xpm", &texture[2].width, &texture[2].height);
    texture[2].data = (int *)mlx_get_data_addr(texture[2].img_ptr, &texture[2].bpp, &texture[2].size_line, &texture[2].endian);
    texture[3].height = 100;
    texture[3].width = 100;
    texture[3].img_ptr = mlx_xpm_file_to_image(mlx, "src/west.xpm", &texture[3].width, &texture[3].height);
    texture[3].data = (int *)mlx_get_data_addr(texture[3].img_ptr, &texture[3].bpp, &texture[3].size_line, &texture[3].endian);

    get_color_px(dt, img, texture);
}
