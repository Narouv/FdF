/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:17:38 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/29 16:19:30 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	ft_transform_point(t_vec *point, t_mlxinfo *info)
{
	float	s;
	int		o_x;
	int		o_y;

	s = info->scale;
	o_x = info->pos_x;
	o_y = info->pos_y;
	point->x = nearbyintf((point->x * s) + o_x);
	point->y = nearbyintf((point->y * s) + o_y);
}

t_vec	*ft_calc_point(t_mlxinfo *info, int *cont)
{
	t_matrices	*matrices;
	float		*r_rot;
	t_vec		*r_proj;

	matrices = info->matrices;
	r_rot = ft_apply_rot(info, matrices->curr_rot_mat, cont);
	if (info->p)
		r_proj = ft_apply_wp(info, r_rot);
	else
		r_proj = ft_apply_proj(info, matrices->proj_mat, r_rot);
	free(r_rot);
	ft_transform_point(r_proj, info);
	return (r_proj);
}

void	ft_verify_points(t_mlxinfo *info, int *cont, int *cont2)
{
	t_vec	*one;
	t_vec	*two;

	one = ft_calc_point(info, cont);
	two = ft_calc_point(info, cont2);
	ft_plot_line(one, two, info->image);
	free(two);
	free(one);
}

void	ft_connect_line(t_mlxinfo *info, t_list *head)
{
	int		**cont;
	int		**cont2;
	int		cntr;

	cont = head->content;
	cntr = 0;
	while (cont[cntr])
	{
		if (cont[cntr + 1])
			ft_verify_points(info, cont[cntr], cont[cntr + 1]);
		if (head->next->content)
		{
			cont2 = ((int **)head->next->content);
			if (cont2[cntr])
				ft_verify_points(info, cont[cntr], cont2[cntr]);
		}
		cntr++;
	}
}

float	**ft_projection(t_mlxinfo *info)
{
	float	**pm;
	int		cntr;

	ft_bzero(pm = malloc(2 * sizeof(float *)), 2 * sizeof(float *));
	if (!pm)
		cleanup(info, "pm alloc fail");
	cntr = 0;
	while (cntr < 2)
	{
		ft_bzero(pm[cntr] = malloc(3 * sizeof(float)), 3 * sizeof(float));
		if (!pm[cntr])
			cleanup(info, "pm cntr alloc fail");
		cntr++;
	}
	pm[0][0] = 1;
	pm[0][1] = 0;
	pm[0][2] = 0;
	pm[1][0] = 0;
	pm[1][1] = 1;
	pm[1][2] = 0;
	return (pm);
}
