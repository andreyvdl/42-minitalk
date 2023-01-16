/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:10:25 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 10:58:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;
	size_t	memlmt;

	memlmt = nmemb * size;
	if (memlmt / size != nmemb || memlmt / nmemb != size)
		return (0x0);
	arr = (char *)malloc(nmemb * size);
	if (arr == 0x0)
		return (0x0);
	i = 0;
	while (nmemb * size != i)
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *)arr);
}
