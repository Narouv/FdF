/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:52:37 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/28 13:10:39 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	ft_free_matrix(float **matrix, int size)
{
	int cntr;

	cntr = 0;
	while (cntr < size)
		free(matrix[cntr++]);
	free(matrix);
}

void	cleanup(t_mlxinfo *info, char *msg)
{
	t_list	*head;
	t_list	*n;
	int		**cont;
	int		cntr;

	head = info->matrices->object_points;
	while (head)
	{
		cont = head->content;
		n = head->next;
		cntr = 0;
		if (cont)
			while (cont[cntr])
				free(cont[cntr++]);
		free(cont);
		free(head);
		head = n;
	}
	if (info->matrices)
	{
		if (info->matrices->proj_mat)
			ft_free_matrix(info->matrices->proj_mat, 2);
		if (info->matrices->curr_rot_mat)
			ft_free_matrix(info->matrices->curr_rot_mat, 3);
		free(info->matrices);
	}
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
