/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:43:20 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 10:57:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sgn;
	int	rslt;

	i = 0;
	rslt = 0;
	sgn = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || ft_isdigit(nptr[i]))
		sgn = 1;
	else if (nptr[i] == '-')
		sgn = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		rslt += (nptr[i] - '0');
		if (ft_isdigit(nptr[i + 1]))
			rslt *= 10;
		i++;
	}
	return (rslt * sgn);
}
