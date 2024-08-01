/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:09:16 by rmichel-          #+#    #+#             */
/*   Updated: 2024/08/01 06:54:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_color(t_data *dt, char *str)
{
	char **split;
	int	n;
	
	split = ft_split(str, ' ');
	printf("---> %s\n", split[0]);
	if (split[0] && split[1] && split[2] && split[3] == NULL)
		n = ft_atoi(split[0]) * 256 * 256 + ft_atoi(split[1]) * 256 + ft_atoi(split[2]);
	return (n);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while(tab[++i])
		free(tab[i]);
	free(tab);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (((int)(unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}

void	param_texture(t_data *data, t_img texture, char *texture_path)
{
	texture.height = 100;
	texture.width = 100;
	texture.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, texture_path, \
&texture.width, &texture.height);
	printf("height = %d, width = %d, texture = %s\n", texture.height, \
texture.width, texture_path);
}

void	keep_texture(t_data *data, char *str)
{
	char	*texture_path;
	int		i;

	i = 2;
	while (str[i] == ' ')
		i++;
	texture_path = ft_strdup(&str[i]);
	if (ft_strncmp(str, "NO ", 3) == 0)
		data->no = init_texture(texture_path, data->mlx_ptr);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		data->so = init_texture(texture_path, data->mlx_ptr);
	else if (ft_strncmp(str, "WO ", 3) == 0)
		data->wo = init_texture(texture_path, data->mlx_ptr);
	else if (ft_strncmp(str, "EO ", 3) == 0)
		data->eo = init_texture(texture_path, data->mlx_ptr);
	else if (ft_strncmp(str, "DO ", 3) == 0)
		data->d_o = init_texture(texture_path, data->mlx_ptr);
	else if (ft_strncmp(str, "C ", 2) == 0)
	{
		printf("HEYYYY\n");
		data->c = init_color(data, texture_path);
	}
	else if (ft_strncmp(str, "F ", 2) == 0)
		data->f = init_color(data, texture_path);
	free(texture_path);
}

int	skip_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	if (str[i] == '1')
		return (2);
	return (0);
}

void	parsing(t_data *data, char *str)
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
		keep_texture(data, &str[i]);
}

void	init_player(t_data *data, int x, int y , char c)
{
    printf("direction = %c\n", c);
	data->player.x = x + 0.2;	
	data->player.y = y + 0.2;	
	if (c == 'S')
	    data->corner = M_PI / 2;
    else if (c == 'N')
	    data->corner = -M_PI / 2;
	else if (c == 'W')
	    data->corner = M_PI;
	else if (c == 'S')
	    data->corner = 0;
    data->dir_cam.x = cos(data->corner);
    data->dir_cam.y = sin(data->corner);
    data->plane_cam.x = -sin(data->corner);
    data->plane_cam.y = cos(data->corner);
	data->mv = 0.05;
	data->x_mouse = WIDTH / 2;
}

void    find_player_pos (t_data *data)
{
    int x;
    int y;
    int stop;

    y = 0;
    stop = 1;
    while(data->map[++y] && stop)
    {
        x = -1;
        while(data->map[y][++x] && stop)
        {
            if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
                return (init_player(data, x, y, data->map[y][x]));           
        }
    }
}

void	pars(t_data *data)
{
	int		fd;
	char	*line;
	int		stop;
	char	**env;
	char	*str;
	int		i;

	stop = 0;
	str = "\0";
	fd = open("map.cub", 0);
	if (!fd)
		printf("error\n");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (i > 0)
			str = ft_strjoin_cub(str, line, 1 , 0);
		else
			str = ft_strjoin_cub(str, line, 0 , 0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	env = ft_split(str, '\n');
	i = 0;
	while (env[i] && stop != 1)
	{
		printf("%s\n", env[i]);
		if (skip_line(env[i]) == 1)
			i++;
		else
		{
			if (skip_line(env[i]) == 2)
			{
				create_map(data, env, i);
				if (data->map == NULL)
				{
					mlx_destroy_image(data->mlx_ptr, data->no.img_ptr);
					mlx_destroy_image(data->mlx_ptr, data->so.img_ptr);
					mlx_destroy_image(data->mlx_ptr, data->eo.img_ptr);
					mlx_destroy_image(data->mlx_ptr, data->wo.img_ptr);
					mlx_destroy_window(data->mlx_ptr, data->win_ptr);
					mlx_destroy_display(data->mlx_ptr);
					free(data->mlx_ptr);
					ft_free(env);
					exit (EXIT_SUCCESS);
				}
				stop = 1;
				break ;
			}
			parsing(data, env[i]);
			i++;
		}
	}
	free_tab(env);
	free(str);
    find_player_pos(data);
}
