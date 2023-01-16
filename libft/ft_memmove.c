/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:28:52 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:01:24 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	if (tmp_dst < tmp_src)
		ft_memcpy(tmp_dst, tmp_src, n);
	else
	{
		while (n--)
			tmp_dst[n] = tmp_src[n];
	}
	return (dst);
}
