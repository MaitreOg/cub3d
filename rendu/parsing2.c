#include "cube3d.h"

int	init_color(t_data *dt, char *str)
{
	char	**split;
	int		n;

	split = ft_split(str, ' ');
	printf("---> %s\n", split[0]);
	if (split[0] && split[1] && split[2] && split[3] == NULL)
	{
		n = ft_atoi(split[0]) * 256 * 256;
		n += ft_atoi(split[1]) * 256 + ft_atoi(split[2]);
	}
	return (n);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
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
