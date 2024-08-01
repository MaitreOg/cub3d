/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:54:30 by rmichel-          #+#    #+#             */
/*   Updated: 2024/07/31 16:41:46 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	*ft_memset(void *pt, int c, size_t n)
{
	size_t	temp;

	temp = 0;
	while (temp < n)
	{
		((char *)pt)[temp] = c;
		temp++;
	}
	return (pt);
}
