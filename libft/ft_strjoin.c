/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:01:10 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/08 23:35:33 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
