/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:37:34 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 03:13:53 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	if (!lst || !f)
		return (NULL);
	newlst = ft_lstnew(f(lst->content));
	if (!newlst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
			ft_lstclear(&newlst, del);
		ft_lstadd_back(&newlst, newnode);
	}
	return (newlst);
}
