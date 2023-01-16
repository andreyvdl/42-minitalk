/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:04:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 10:58:37 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	decimal(int nbr);
static int	ft_abs(int n);

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;

	size = decimal(n);
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (arr == 0x0)
		return (0x0);
	if (n == 0)
		arr[0] = '0';
	else if (n < 0)
		arr[0] = '-';
	arr[size--] = '\0';
	while (n != 0 && size >= 0)
	{
		arr[size--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (arr);
}

static int	decimal(int nbr)
{
	int	house;

	house = 0;
	if (nbr <= 0)
		house = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		house++;
	}
	return (house);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
