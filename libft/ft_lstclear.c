/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:48:19 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 01:57:46 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}

// void    ft_lstclear(t_list **lst, void (*del)(void *))
// {
//     t_list    *curr;
//     t_list    *next;

//     if (!lst)
//         return ;
//     curr = *lst;
//     while (curr)
//     {
//         next = curr->next;
//         ft_lstdelone(curr, del);
//         free(curr);
//         curr = next;
//     }
// }
