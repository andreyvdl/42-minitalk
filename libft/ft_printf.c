/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:34:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:01:40 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	al;
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (!format)
		return (-1);
	va_start(al, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			n += prnt_ths(format[i + 1], al);
			i++;
		}
		else
			n += (int)write(1, &format[i], 1);
		i++;
	}
	va_end(al);
	return (n);
}

int	prnt_ths(char c, va_list al)
{
	if (c == 'c')
		return (fake_putchr(va_arg(al, int)));
	else if (c == 's')
		return (fake_putstr(va_arg(al, char *)));
	else if (c == 'p')
		return (ptr_2_hex(va_arg(al, U_LI)));
	else if (c == 'i' || c == 'd')
		return (fake_itoa(va_arg(al, int)));
	else if (c == 'u')
		return (u_itoa(va_arg(al, unsigned int)));
	else if (c == 'x')
		return (hex_lwr(va_arg(al, unsigned int)));
	else if (c == 'X')
		return (hex_uppr(va_arg(al, unsigned int)));
	else if (c == '%')
		return ((int)write(1, "%", 1));
	else
		return ((int)write(1, "%", 1) + (int)write(1, &c, 1));
}

int	fake_putstr(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (!str)
		return ((int)write(1, "(null)", 6));
	while (str[i])
	{
		n += (int)write(1, &str[i], 1);
		i++;
	}
	return (n);
}

int	fake_putchr(int c)
{
	return ((int)write(1, &c, 1));
}
