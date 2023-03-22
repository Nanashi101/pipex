/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:47:53 by jael-mor          #+#    #+#             */
/*   Updated: 2022/10/19 08:04:14 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == (unsigned char)c)
			return (&p[i]);
		i++;
	}
	if (p[i] == (unsigned char)c)
		return (&p[i]);
	return (NULL);
}
