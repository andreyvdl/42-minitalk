/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:52:35 by adantas-          #+#    #+#             */
/*   Updated: 2022/10/13 16:17:29 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define U_LI unsigned long int

// ft_print.c functions
int	fake_putchr(int c);
int	fake_putstr(char *str);
int	prnt_ths(char c, va_list al);
int	ft_printf(const char *format, ...);

// hex_handler.c functions
int	hex_lwr(unsigned long hex);
int	hex_uppr(unsigned long hex);
int	ptr_2_hex(unsigned long int ptr);

// nbr_handler.c functions
int	fake_itoa(int nbr);
int	u_itoa(unsigned int nbr);

#endif