/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: rmichel- <rmichel-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/31 15:35:47 by rmichel-		  #+#	#+#			 */
/*   Updated: 2024/07/31 17:53:10 by rmichel-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cube3d.h"

int	check_e(char **map, int x, int y)
{
	if (x == -1 || y == -1)
		return (printf("%d %d : %c\n", y, x, map[x][y]), 1);
	if (map[x] == NULL || map[x][y] == '\0')
		return (printf("%d %d : %c\n", y, x, map[x][y]), 1);
	if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != 'N'
		&& map[x][y] != 'S' && map[x][y] != 'E' && map[x][y] != 'W'
		&& map[x][y] != '2')
		return (printf("%d %d : %c\n", y, x, map[x][y]), 1);
	return (0);
}

int	check_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == '0')
			{
				if (check_e(map, x - 1, y - 1) || check_e(map, x - 1, y)
					|| check_e(map, x - 1, y + 1) || check_e(map, x, y - 1)
					|| check_e(map, x - 1, y + 1) || check_e(map, x + 1, y - 1)
					|| check_e(map, x + 1, y) || check_e(map, x + 1, y + 1))
					return (printf("%d %d : %c\n", y, x, map[x][y]), 1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

char	**create_map(t_data *data, char **parsing, int i)
{
	int		y;
	char	**map;
	char	*str;

	y = i;
	while (parsing[y])
		y++;
	data->map = malloc(sizeof(char *) * (y - i + 2));
	y = 0;
	while (parsing[i])
	{
		data->map[y] = ft_strdup(parsing[i]);
		y++;
		i++;
	}
	data->map[y] = NULL;
	preset_door(data);
	if (check_map(data->map) == 1)
	{
		printf("????");
		ft_free(data->map);
		data->map = NULL;
		return (NULL);
	}
	return (map);
}
