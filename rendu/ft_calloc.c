/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:39:38 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/06 15:22:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_all_tex(t_data *dt)
{
	dt->so.img_ptr = NULL;
	dt->so.init = -1;
	dt->no.img_ptr = NULL;
	dt->no.init = -1;
	dt->eo.img_ptr = NULL;
	dt->eo.init = -1;
	dt->wo.img_ptr = NULL;
	dt->wo.init = -1;
	dt->d_o.img_ptr = NULL;
	dt->d_o.init = -1;
	dt->c = -1;
	dt->f = -1;
}

int	check_data_text(t_data *dt)
{
	if (dt->so.init < 0 || dt->no.init < 0 || dt->eo.init < 0 || \
	dt->wo.init < 0 || dt->d_o.init < 0 || dt->c < 0 || dt->f < 0)
		return (1);
	return (0);
}

void	key_destroyed2(t_data *dt)
{
	if (dt->no.img_ptr)
		mlx_destroy_image(dt->mlx_ptr, dt->no.img_ptr);
	if (dt->so.img_ptr)
		mlx_destroy_image(dt->mlx_ptr, dt->so.img_ptr);
	if (dt->eo.img_ptr)
		mlx_destroy_image(dt->mlx_ptr, dt->eo.img_ptr);
	if (dt->wo.img_ptr)
		mlx_destroy_image(dt->mlx_ptr, dt->wo.img_ptr);
	if (dt->d_o.img_ptr)
		mlx_destroy_image(dt->mlx_ptr, dt->d_o.img_ptr);
	mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
	mlx_destroy_display(dt->mlx_ptr);
	free(dt->mlx_ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*to_allocate;

	if (nmemb * size == 0)
		return (malloc(0));
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	to_allocate = malloc(nmemb * size);
	if (to_allocate == NULL)
		return (NULL);
	ft_bzero(to_allocate, nmemb * size);
	return (to_allocate);
}
