/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:48:23 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/17 21:58:02 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printarg(int flag, va_list ptr, int *freturn)
{
	if (flag == 1)
		ft_putchar(va_arg(ptr, int), 1, freturn);
	else if (flag == 2)
		ft_putstr(va_arg(ptr, char *), 1, freturn);
	else if (flag == 3)
		ft_putnbr(va_arg(ptr, int), 1, freturn);
	else if (flag == 4)
		ft_putuns(va_arg(ptr, unsigned int), 1, freturn);
	else if (flag == 5)
		ft_lowerhex(va_arg(ptr, unsigned int), freturn);
	else if (flag == 6)
		ft_upperhex(va_arg(ptr, unsigned int), freturn);
	else if (flag == 7)
		ft_putptr(va_arg(ptr, void *), freturn);
	else if (flag == 8)
		ft_putchar('%', 1, freturn);
}

int	ft_printf(char const *format, ...)
{
	va_list	ptr;
	int		freturn;

	if (write(1, 0, 0) == -1)
		return (-1);
	freturn = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (ft_flags(format) > 0 && ft_flags(format) < 9)
		{
			ft_printarg(ft_flags(format), ptr, &freturn);
			format += 2;
		}
		else if (ft_flags(format) == 9)
			format++;
		else if (*format)
		{
			ft_putchar(*format, 1, &freturn);
			format++;
		}
	}
	va_end(ptr);
	return (freturn);
}
