#include "cube3d.h"

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
