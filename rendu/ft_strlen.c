/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:49:23 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/02 12:39:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	add_color(t_data *dt)
{
	int	x;

	x = -1;
	while (++x < WIDTH * HEIGHT / 2)
		dt->img.data[x] = dt->c;
	while (++x < WIDTH * HEIGHT)
		dt->img.data[x] = dt->f;
}

size_t	ft_strlen(const char *str)
{
	size_t	looked_char;

	looked_char = 0;
	while (str[looked_char] != '\0')
		looked_char++;
	return (looked_char);
}

void	ft_free(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
