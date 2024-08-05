/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creaator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:29:34 by marvin            #+#    #+#             */
/*   Updated: 2024/08/05 11:29:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    put_square_to_window(t_data *dt, t_img color[], int fd, int n)
{
    static int x = 0;
    static int y = 0;

    if (y > dt->size[1])
        return ;
    mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, color[n].img_ptr x, y);
    if (n == '4')
        write(fd, "N", 1);
    else
        write(fd, )
    x += 64;
    if (x >= dt->size[0])
    {
        x = 0;
        y += 64;
    }
    return ;
}
