/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 22:48:48 by jael-mor          #+#    #+#             */
/*   Updated: 2022/10/18 12:53:17 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
