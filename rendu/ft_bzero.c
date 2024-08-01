/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmichel- <rmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:05 by rmichel-          #+#    #+#             */
/*   Updated: 2024/07/31 16:41:35 by rmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nbr)
{
	int	nbr_to_return;
	int	looked_char;
	int	sign;

	sign = 1;
	looked_char = 0;
	nbr_to_return = 0;
	while ((nbr[looked_char] >= 9 && nbr[looked_char] <= 13) || \
			nbr[looked_char] == 32)
		looked_char++;
	if (nbr[looked_char] == '-')
		sign *= -1;
	if (nbr[looked_char] == '+' || nbr[looked_char] == '-')
		looked_char++;
	while (ft_isdigit(nbr[looked_char]))
	{
		nbr_to_return = 10 * nbr_to_return + (nbr[looked_char] - 48);
		looked_char++;
	}
	return (nbr_to_return * sign);
}

void	ft_bzero(void *pt, size_t n)
{
	ft_memset(pt, 0, n);
	return ;
}
