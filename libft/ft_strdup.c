/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:43:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:02:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;

	if (s == 0x0)
		return (0x0);
	copy = (char *)malloc(ft_strlen(s) + 1);
	if (copy == 0x0)
		return (0x0);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = ((char *)s)[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
