/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:20:05 by adantas-          #+#    #+#             */
/*   Updated: 2022/09/17 18:20:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nw_item;

	nw_item = (t_list *)malloc(sizeof(t_list));
	if (nw_item == 0x0)
		return (0x0);
	nw_item->content = content;
	nw_item->next = 0x0;
	return (nw_item);
}
