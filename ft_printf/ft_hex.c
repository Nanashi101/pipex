/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:29:57 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/17 21:42:12 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lowerhex(unsigned long int n, int *freturn)
{
	if (n <= 15)
	{
		ft_putchar("0123456789abcdef"[n], 1, freturn);
	}
	else if (n > 15)
	{
		ft_lowerhex(n / 16, freturn);
		ft_lowerhex(n % 16, freturn);
	}
}

void	ft_upperhex(unsigned long int n, int *freturn)
{
	if (n <= 15)
	{
		ft_putchar("0123456789ABCDEF"[n], 1, freturn);
	}
	else if (n > 15)
	{
		ft_upperhex(n / 16, freturn);
		ft_upperhex(n % 16, freturn);
	}
}
