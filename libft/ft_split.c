/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:21:06 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 09:47:04 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
