/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 03:12:32 by jael-mor          #+#    #+#             */
/*   Updated: 2022/10/19 08:02:41 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*p;
	size_t			i;

	i = 0;
	a = (unsigned char)c;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == a)
		{
			return ((void *)&p[i]);
		}
		i++;
	}
	return (NULL);
}
