/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:19:05 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/24 10:26:49 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	k;
	size_t	sum_of_len;
	size_t	i;
	char	*arr;

	if (size == 0 || size < ft_strlen(dst))
		return (size + ft_strlen(src));
	arr = (char *)src;
	j = ft_strlen(dst);
	k = ft_strlen(src);
	sum_of_len = j + k;
	i = 0;
	while (arr[i] && j < size - 1 && size != 0)
	{
		dst[j] = arr[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (sum_of_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	sum_of_size;
	char	*p;

	if (s == NULL)
		return (0);
	j = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	sum_of_size = ft_strlen(s + start);
	if (sum_of_size < len)
		len = sum_of_size;
	p = (char *)(malloc((len + 1) * sizeof(char)));
	if (!p)
		return (0);
	while (s[start] && j < len)
		p[j++] = s[start++];
	p[j] = '\0';
	return (p);
}
