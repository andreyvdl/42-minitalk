/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:08:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 11:02:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char cut);
static void		insrt_str(char const *src, char **dst, char dlmt);

char	**ft_split(char const *s, char c)
{
	char	**strv;

	strv = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	insrt_str(s, strv, c);
	return (strv);
}

static size_t	count_words(char const *str, char cut)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		while (str[i] == cut)
			i++;
		if (str[i] != cut && str[i])
			words++;
		while (str[i] != cut && str[i])
			i++;
	}
	return (words);
}

static void	insrt_str(char const *src, char **dst, char dlmt)
{
	size_t	i;
	size_t	lttr;
	size_t	spc;
	size_t	start;

	i = 0;
	spc = 0;
	while (src[i] != '\0')
	{
		lttr = 0;
		while (src[i] == dlmt)
			i++;
		start = i;
		while (src[i] != dlmt && src[i])
		{
			i++;
			lttr++;
		}
		if (lttr != 0)
			dst[spc++] = ft_substr(src, start, lttr);
	}
}
