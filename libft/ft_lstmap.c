/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:02:09 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/12 10:59:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = 0x0;
	while (lst != 0x0)
	{
		ft_lstadd_back(&new_lst, ft_lstnew(f(lst->content)));
		if (new_lst == 0x0)
		{
			ft_lstclear(&new_lst, del);
			return (0x0);
		}
		lst = lst->next;
	}
	return (new_lst);
}
