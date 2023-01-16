/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:59:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:03:34 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == 0x0)
		return ((char *)big);
	else if (little[0] == '\0' && big[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (little[j] == big[i + j] && i + j != len)
		{
			if (little[j + 1] == '\0')
				return (&((char *)big)[i]);
			j++;
		}
		i++;
	}
	return (0x0);
}
