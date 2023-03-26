/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:10:56 by rnauke            #+#    #+#             */
/*   Updated: 2022/04/16 14:51:36 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	cntr;

	if (!lst)
		return (0);
	cntr = 1;
	while (lst->next != NULL)
	{
		cntr++;
		lst = lst->next;
	}
	return (cntr);
}
