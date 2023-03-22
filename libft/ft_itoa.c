/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:00:52 by marvin            #+#    #+#             */
/*   Updated: 2022/10/28 09:57:28 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_of_int(long int i)
{
	int	k;

	k = 0;
	if (i == 0)
		k = 1;
	if (i < 0)
	{
		i *= -1;
		k = 1;
	}
	while (i > 0)
	{
		i = i / 10;
		k++;
	}
	return (k);
}

static char	*ft_return(char *s)
{
	s[0] = 48;
	return (s);
}

char	*ft_itoa(int n)
{
	int					i;
	char				*str;
	long int			res;

	i = len_of_int(n);
	res = n;
	str = (char *)(malloc(sizeof(char) * (i + 1)));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n == 0)
		return (ft_return(str));
	if (n < 0)
	{
		str[0] = '-';
		res *= -1;
	}
	while (res >= 1)
	{
		str[i] = 48 + (res % 10);
		res = res / 10;
		i--;
	}
	return (str);
}
