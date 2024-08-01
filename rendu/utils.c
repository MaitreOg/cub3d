/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:34:09 by smarty            #+#    #+#             */
/*   Updated: 2024/08/02 00:34:10 by smarty           ###   ########.fr       */
/*                                                                            */
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

char	*ft_strjoin_cub(char *s1, char *s2, int a, int b)
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
	if (a == 1)
		free(s1);
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = 0;
	if (a == 2)
		free(s2);
	return (str);
}
