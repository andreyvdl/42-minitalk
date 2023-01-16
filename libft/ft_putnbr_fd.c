/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:15:49 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:02:10 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n);

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < -9)
			ft_putnbr_fd((n / 10) * -1, fd);
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = ft_abs(n % 10) + '0';
	ft_putchar_fd(c, fd);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
