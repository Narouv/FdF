/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:52:37 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/26 14:43:37 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	cleanup(t_mlxinfo *info, char *msg)
{
	t_list	*head;
	int		**cont;
	int		cntr;

	head = info->matrices->object_points;
	if (head)
	{
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
	system("leaks fdf");
	if (!msg)
		exit(EXIT_SUCCESS);
	else
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
}
