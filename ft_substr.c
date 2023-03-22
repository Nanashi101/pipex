/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:51:51 by jael-mor          #+#    #+#             */
/*   Updated: 2023/03/22 22:22:11 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	sum_of_size;
	char	*p;

	if (s == NULL)
		return (0);
	j = 0;
	if (ft_strlen(s) < start)
		return (strdup(""));
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
