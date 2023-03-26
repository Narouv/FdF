/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:17:38 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/26 16:29:05 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

float	*ft_apply_rot(t_mlxinfo *info, float **rotationMatrix, int *vertex)
{
	float	*result;
	int		cc;

	ft_bzero(result = malloc(sizeof(3 * sizeof(float))), 3 * sizeof(float));
	if (!result)
		cleanup(info, "apply rot alloc fail");
	cc = 0;
	while (cc < 3)
	{
		// ft_printf("cc:%i\n", cc);
		// ft_printf("rm: %i\n", rotationMatrix[0][cc]);
		result[0] += rotationMatrix[0][cc] * vertex[cc];
		
		// ft_printf("rm: %i\n", rotationMatrix[1][cc]);
		// ft_printf("first\n");
		result[1] += rotationMatrix[1][cc] * vertex[cc];
		
		// ft_printf("vertex: %i", vertex[cc]);
		// ft_printf("rm: %i\n", rotationMatrix[2][cc]);
		// ft_printf("result %i", result[2]);
		// ft_printf("2nd\n");
		result[2] += rotationMatrix[2][cc] * vertex[cc];
		// ft_printf("written\n");
		cc++;
	}
	return (result);
}

t_vec	*ft_apply_proj(t_mlxinfo *info, float **projectionMatrix, float *rotatedPoints)
{
	t_vec	*result;
	int		cc;

	ft_bzero(result = malloc(sizeof(t_vec)), sizeof(t_vec));
	if (!result)
		cleanup(info, "apply rot alloc fail");
	cc = 0;
	while (cc < 3)
	{
		result->x += projectionMatrix[0][cc] * rotatedPoints[cc];
		result->y += projectionMatrix[1][cc] * rotatedPoints[cc];
		cc++;
	}
	return (result);
}

void	ft_transform_point(t_vec *point, t_mlxinfo *info)
{
	int	s;
	int	o_x;
	int	o_y;

	s = info->scale;
	o_x = info->pos_x;
	o_y = info->pos_y;
	point->x = nearbyintf(point->x * s + o_x);
	point->y = nearbyintf(point->y * s + o_y);
}

t_vec	*ft_calc_point(t_mlxinfo *info, int *cont)
{
	t_matrices	*matrices;
	float		*r_rot;
	t_vec		*r_proj;

	matrices = info->matrices;
	r_rot = ft_apply_rot(info, matrices->curr_rot_mat, cont);
	r_proj = ft_apply_proj(info, matrices->proj_mat, r_rot);
	free(r_rot);
	ft_transform_point(r_proj, info);
	return (r_proj);
}

void	ft_line(t_mlxinfo *info, t_vec *p0, t_vec *p1, int32_t color)
{
	ft_plot_line(p0, p1, info->image, color);
}

void	ft_connect_line(t_mlxinfo *info, t_list *head)
{
	int		**cont;
	int		**cont2;
	int		cntr;
	t_vec	*result;
	t_vec	*result2;
	t_vec	*result3;

	cont = head->content;
	cntr = 0;
	while (cont[cntr])
	{
		result = ft_calc_point(info, cont[cntr]);
		if (cont[cntr + 1])
		{
			result2 = ft_calc_point(info, cont[cntr + 1]);
			ft_line(info, result, result2, 0xFF00FFFF);
			free(result2);
		}
		if (head->next->content)
		{
			cont2 = ((int **)head->next->content);
			if (cont2[cntr+1])
			{
				
				result3 = ft_calc_point(info, cont2[cntr+1]);
				ft_line(info, result, result3, 0xFFFFFFFF);
				free(result3);
			}
		}
		cntr++;
		free(result);
	}
}

//current problem: the connecting edge to the next line is one BEHIND the current cntr (pls understand this)
//why is zoom in so snappy?

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
