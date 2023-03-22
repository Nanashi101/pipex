/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:49:12 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/17 21:42:52 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int fd, int *freturn)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*freturn += 11;
	}
	else if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write (fd, &c, 1);
		*freturn += 1;
	}
	else if (n < 0)
	{
		write (fd, "-", 1);
		*freturn += 1;
		ft_putnbr(-n, fd, freturn);
	}
	else if (n > 0)
	{
		ft_putnbr(n / 10, fd, freturn);
		ft_putnbr(n % 10, fd, freturn);
	}
}
