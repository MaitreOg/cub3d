/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:09:16 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/05 18:41:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parsing(t_data *data, char *str, char **env, char *s)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (ft_strncmp(&str[i], "NO", 2) == 0 || ft_strncmp(&str[i], "SO", 2) == 0
		|| ft_strncmp(&str[i], "WO", 2) == 0
		|| ft_strncmp(&str[i], "EO", 2) == 0
		|| ft_strncmp(&str[i], "DO", 2) == 0
		|| ft_strncmp(&str[i], "C", 1) == 0
		|| ft_strncmp(&str[i], "F", 1) == 0)
		keep_texture(data, &str[i], env, s);
	else
		return (printf("Error\nError while reading map (Unreconized Token ?)\n"), \
		key_destroyed2(data), free_tab(env), free(s), exit(1));
}

void	init_player(t_data *data, int x, int y, char c)
{
	data->player.x = x + 0.2;
	data->player.y = y + 0.2;
	if (c == 'S')
		data->corner = M_PI / 2;
	else if (c == 'N')
		data->corner = -M_PI / 2;
	else if (c == 'W')
		data->corner = M_PI;
	else if (c == 'E')
		data->corner = 0;
	data->dir_cam.x = cos(data->corner);
	data->dir_cam.y = sin(data->corner);
	data->plane_cam.x = -sin(data->corner);
	data->plane_cam.y = cos(data->corner);
	data->mv = 0.05;
	data->x_mouse = WIDTH / 2;
}

void	find_player_pos(t_data *data)
{
	int	x;
	int	y;
	int	stop;

	y = 0;
	stop = 1;
	while (data->map[++y] && stop)
	{
		x = -1;
		while (data->map[y][++x] && stop)
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'W' || data->map[y][x] == 'E')
				return (init_player(data, x, y, data->map[y][x]));
		}
	}
}

void	pars_env(t_data *data, char *str)
{
	char	**env;
	int		i;
	int		stop;

	stop = 0;
	env = ft_split(str, '\n');
	i = 0;
	while (env[i] && stop != 1)
	{
		if (skip_line(env[i]) != 1)
		{
			if (skip_line(env[i]) == 2)
			{
				create_map(data, env, i);
				if (data->map == NULL)
					return (key_destroyed2(data), free_tab(env), free(str), exit(1));
				stop = 1;
				break ;
			}
			parsing(data, env[i], env, str);
		}
		i++;
	}
	free_tab(env);
}

void	pars(t_data *data, char **av)
{
	int		fd;
	char	*line;
	char	*str;
	int		i;

	str = "\0";
	fd = open(av[1], 0);
	if (fd == -1)
		return (printf("Error\nError while opening the file\n"), key_destroyed2(data), exit(1));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (i > 0)
			str = ft_strjoin_cub(str, line, 1);
		else
			str = ft_strjoin_cub(str, line, 0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	pars_env(data, str);
	free(str);
	find_player_pos(data);
}
