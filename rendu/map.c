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

int	count_word(const char *s, char c)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	if (s[0] != c && s[0])
		nb++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			nb++;
		i++;
	}
	return (nb);
}

char	**cpyword(char	**str, char *s, char c, int i)
{
	int	y;
	int	word;

	y = 0;
	word = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i + y] != c && s[i + y])
			y++;
		str[word] = (char *)malloc (sizeof(char) * y + 1);
		if (!str[word])
			return (NULL);
		y = 0;
		while (s[i] != c && s[i])
			str[word][y++] = s[i++];
		str[word][y] = '\0';
		y = 0;
		while (s[i] == c && s[i])
			i++;
		word++;
	}
	str[word] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		nb;
	char	**ss;
	int		i;

	i = 0;
	nb = count_word(s, c);
	ss = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!ss)
		return (NULL);
	return (cpyword(ss, s, c, i));
}

int	ft_strlen_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_cub(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = (ft_strlen_cub(s1) + ft_strlen_cub(s2));
	j = 0;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	return (str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*result;

	i = 0;
	while (str[i])
		i++;
	if (i == 0)
		return (NULL);
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (str[++i])
		result[i] = str[i];
	result[i] = 0;
	return (result);
}

int check_e(char **map, int x, int y)
{
	if (x == -1 || y == -1)
		return (printf("%d %d : %c\n", y, x, map[x][y]), 1);
	if (map[x] == NULL || map[x][y] == '\0')
		return (printf("%d %d : %c\n", y, x, map[x][y]), 1);
	if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != 'N' && map[x][y] != 'S' && map[x][y] != 'E' && map[x][y] != 'W' && map[x][y] != '2')
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
				if (check_e(map, x - 1, y - 1) || check_e(map, x - 1, y) || check_e(map, x - 1, y + 1) || check_e(map, x, y - 1) || check_e(map, x - 1, y + 1) || check_e(map, x + 1, y - 1) || check_e(map, x + 1, y) || check_e(map, x + 1, y + 1))
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
		str = ft_strtrim(parsing[i], " ");
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
