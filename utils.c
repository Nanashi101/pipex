/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:24:32 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/26 03:12:27 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_words(char const *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c && j == 0)
		{
			j = 1;
			k++;
		}
		else if (str[i] == c)
		{
			j = 0;
		}
		i++;
	}
	return (k);
}

static size_t	ft_char(char const *str, size_t i, char c)
{
	size_t	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**new;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (str == 0)
		return (NULL);
	new = (char **)malloc((ft_words(str, c) + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (j < ft_words(str, c))
	{
		while (str[i] == c && str[i])
			i++;
		new[j] = ft_substr(&str[i], 0, (ft_char(str, i, c)));
		if (!(new[j]))
			return (ft_free(new));
		i += ft_char(str, i, c);
		j++;
	}
	new[j] = 0;
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*p2;

	if (!s1 || !s2)
		return (0);
	p2 = (malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	if (!p2)
		return (0);
	i = ft_strlen(s1);
	ft_strlcpy(p2, s1, i + 1);
	ft_strlcat(p2 + i, s2, ft_strlen(s2) + 1);
	return (p2);
}
