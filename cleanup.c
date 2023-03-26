/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:52:37 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/25 18:58:51 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/FdF.h"

void	cleanup(t_mlxinfo *info)
{
	t_list	*head;
	int		**cont;
	int		cntr;

	if (head)
	{
		head = info->matrices->object_points;
		while (head->next)
		{
			cont = head->content;
			cntr = 0;
			while (cont[cntr + 1])
				free(cont[cntr++]);
			free(cont);
			head = head->next;
		}
		free(head);
	}
	if (info->matrices)
		free(info->matrices);
	if (info)
		free(info);
	exit(EXIT_FAILURE);
}
