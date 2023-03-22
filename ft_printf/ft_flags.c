/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:33:09 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/17 03:30:03 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags(const char *formatter)
{
	if (*formatter == '%' && *(formatter + 1) == 'c')
		return (1);
	else if (*formatter == '%' && *(formatter + 1) == 's')
		return (2);
	else if (*formatter == '%' && (*(formatter + 1) == 'd'
			|| *(formatter + 1) == 'i'))
		return (3);
	else if (*formatter == '%' && *(formatter + 1) == 'u')
		return (4);
	else if (*formatter == '%' && *(formatter + 1) == 'x')
		return (5);
	else if (*formatter == '%' && *(formatter + 1) == 'X')
		return (6);
	else if (*formatter == '%' && *(formatter + 1) == 'p')
		return (7);
	else if (*formatter == '%' && *(formatter + 1) == '%')
		return (8);
	else if (*formatter == '%')
		return (9);
	return (0);
}
