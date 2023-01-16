/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:30:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:03:53 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	init;
	size_t	end;
	char	*str;

	if (s1 == 0x0)
		return (0x0);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	init = i;
	i = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[i]) && i > init)
		i--;
	end = i + 1;
	str = (char *)malloc(sizeof(char) * (end - init) + 1);
	if (str == 0x0)
		return (0x0);
	i = 0;
	while (init != end)
		str[i++] = s1[init++];
	str[i] = '\0';
	return (str);
}
