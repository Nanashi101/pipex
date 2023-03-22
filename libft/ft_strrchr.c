/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:38:25 by jael-mor          #+#    #+#             */
/*   Updated: 2022/10/19 08:05:07 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*tmp;

	tmp = NULL;
	while (1)
	{
		if (*str == (unsigned char)c)
			tmp = ((char *)str);
		if (!*str)
			return (tmp);
		str++;
	}
	return (NULL);
}
