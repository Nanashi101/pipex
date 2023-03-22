/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jael-mor <jael-mor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:40:40 by jael-mor          #+#    #+#             */
/*   Updated: 2022/11/17 03:55:14 by jael-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_flags(const char *formatter);
void	ft_putchar(char c, int fd, int *freturn);
void	ft_putstr(char *s, int fd, int *freturn);
void	ft_putnbr(int n, int fd, int *freturn);
void	ft_putuns(unsigned int n, int fd, int *freturn);
void	ft_putptr(void *p, int *freturn);
void	ft_lowerhex(unsigned long int n, int *freturn);
void	ft_upperhex(unsigned long int n, int *freturn);
void	ft_printarg(int flag, va_list ptr, int *freturn);

#endif