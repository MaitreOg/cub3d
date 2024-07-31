
#include "cube3d.h"

void apply_texture(t_img *img, t_img *texture, int x_img, int y_img, int x_tex, int y_tex)
{
    int color = texture->data[y_tex * TEX_WIDTH + x_tex];
    img->data[y_img * img->width + x_img] = color;
}

void get_color_px(t_data *dt, t_img *img)
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
        if (dt->side == 1)
        {
            if (dt->dir_ray.y > 0)
                apply_texture(&dt->img, &dt->NO, dt->x, y, texx, texy);
            else
                apply_texture(&dt->img, &dt->SO, dt->x, y, texx, texy);
        }
        //else if (dt->x >= 320 && dt->side == 1)
          //  apply_texture(&dt->img, &texture[1], dt->x, y, texx, texy);
        else
        {
            if (dt->dir_ray.x > 0)
                apply_texture(&dt->img, &dt->WO, dt->x, y, texx, texy);
            else
                apply_texture(&dt->img, &dt->EO, dt->x, y, texx, texy);
        }
        y++;
    }
}

void create_img(t_data *dt, t_img  *img, void *mlx)
{
    static int lineh = 0;
    t_data dt2;

    dt2 = *dt;
    get_color_px(dt, img);
    /*if (dt2.x > 0)
    {
        dt2.x -= 1;
        dt2.lineh = (lineh + dt->lineh) / 2;
        dt2.to_draw[0] = (-1 * dt2.lineh) / 2 + HEIGHT / 2;
        if (dt2.to_draw[0] < 0)
            dt2.to_draw[0] = 0;
        dt2.to_draw[1] = dt2.lineh / 2 + HEIGHT / 2;
        if (dt2.to_draw[1] >= HEIGHT)
            dt2.to_draw[1] = HEIGHT;
        lineh = dt2.lineh;
        //printf("%d %d\n", d)
        get_color_px(&dt2, img);
        dt2.x -= 1;
        dt2.lineh = dt->lineh; //(lineh + dt2.lineh) / 2;
        dt2.to_draw[0] = (-1 * dt2.lineh) / 2 + HEIGHT / 2;
        if (dt2.to_draw[0] < 0)
            dt2.to_draw[0] = 0;
        dt2.to_draw[1] = dt2.lineh / 2 + HEIGHT / 2;
        if (dt2.to_draw[1] >= HEIGHT)
            dt2.to_draw[1] = HEIGHT;
        lineh = dt2.lineh;
        get_color_px(&dt2, img);
        dt2.x -= 1  ;
        dt2.lineh = lineh; //(lineh + dt2.lineh) / 2;
        dt2.to_draw[0] = (-1 * dt2.lineh) / 2 + HEIGHT / 2;
        if (dt2.to_draw[0] < 0)
            dt2.to_draw[0] = 0;
        dt2.to_draw[1] = dt2.lineh / 2 + HEIGHT / 2;
        if (dt2.to_draw[1] >= HEIGHT)
            dt2.to_draw[1] = HEIGHT;
        lineh = dt2.lineh;
        get_color_px(&dt2, img);
    }
    lineh = dt->lineh;*/
    /*mlx_destroy_image(mlx, texture[0].img_ptr);
    mlx_destroy_image(mlx, texture[1].img_ptr);
    mlx_destroy_image(mlx, texture[2].img_ptr);
    mlx_destroy_image(mlx, texture[3].img_ptr);*/
}
