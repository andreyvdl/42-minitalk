/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:06:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:04:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	str_sz;

	str_sz = ft_strlen(s);
	if (str_sz < start)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = s[str_sz];
		return (str);
	}
	else if (str_sz < len)
		str = (char *)malloc(sizeof(char) * str_sz + 1);
	else if (len == str_sz)
		str = (char *)malloc(sizeof(char) * str_sz - start + 1);
	else
		str = (char *)malloc(sizeof(char) * len + 1);
	if (str == 0x0)
		return (0x0);
	i = 0;
	while (i != len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
