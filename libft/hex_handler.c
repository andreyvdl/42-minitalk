/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:22:36 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:04:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_lwr(unsigned long hex)
{
	if (hex >= 16)
		return (hex_lwr(hex / 16) + (int)write(1, &HEX_L[hex % 16], 1));
	else
		return ((int)write(1, &HEX_L[hex % 16], 1));
}

int	hex_uppr(unsigned long hex)
{
	if (hex >= 16)
		return (hex_uppr(hex / 16) + (int)write(1, &HEX_U[hex % 16], 1));
	else
		return ((int)write(1, &HEX_U[hex % 16], 1));
}

int	ptr_2_hex(unsigned long int ptr)
{
	if (ptr == 0)
		return ((int)write(1, "(nil)", 5));
	else
		return ((int)write(1, "0x", 2) + hex_lwr(ptr));
}
