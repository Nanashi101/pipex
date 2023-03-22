/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:13:03 by marvin            #+#    #+#             */
/*   Updated: 2022/10/25 17:13:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;

	i = 0;
	start = 0;
	if (s1 == NULL || set == NULL)
		return (0);
	while (ft_set(s1[start], set) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (ft_set(s1[end - 1], set) && end > start)
		end--;
	len = end - start + 1;
	str = (char *)(malloc(len));
	if (!str)
		return (0);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
