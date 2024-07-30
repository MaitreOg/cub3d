/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init_values.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: marvin <marvin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/28 12:16:31 by marvin			#+#	#+#			 */
/*   Updated: 2024/07/28 12:16:31 by marvin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cube3d.h"

t_pos   init_side(t_pos dir_ray, t_pos player, t_pos floored, t_pos delta)
{
	t_pos	side_dist;

	if (dir_ray.x < 0)
		side_dist.x = (player.x - floored.x) * delta.x;
	else
		side_dist.x = (floored.x + 1.0 - player.x) * delta.x;
	if (dir_ray.y < 0)
		side_dist.y = (player.y - floored.y) * delta.y;
	else
		side_dist.y = (floored.y + 1.0 - player.y) * delta.y;
	return (side_dist);
}

t_pos	init_step(t_pos dir_ray)
{
	t_pos	step;

	if (dir_ray.x < 0)
		step.x = -1.0;
	else
		step.x = 1.0;
	if (dir_ray.y < 0)
		step.y = -1.0;
	else
		step.y = 1.0;
	return (step);	
}
