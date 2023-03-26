/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:17:38 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/26 01:50:26 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/FdF.h"

float	*ft_apply_rot(float **rotationMatrix, int *vertex)
{
	float	*result;
	int		cb;
	int		cc;

	ft_bzero(result = malloc(sizeof(3 * sizeof(float))), 3 * sizeof(float));
	cb = 0;
	while (cb < 3)
	{
		cc = 0;
		while (cc < 3)
		{
			result[cb] += rotationMatrix[cb][cc] * vertex[cc];
			// printf("rotationMatrix: %f, vertices: %d, rotated_point: %f\n", rotationMatrix[cb][cc], vertex[cc], result[cb]);
			cc++;
		}
		cb++;
	}
	return (result);
}

t_vec	*ft_apply_proj(float **projectionMatrix, float *rotatedPoints)
{
	t_vec	*result;
	int		cc;

	ft_bzero(result = malloc(sizeof(t_vec)), sizeof(t_vec));
	cc = 0;
	while (cc < 3)
	{
		result->x += projectionMatrix[0][cc] * rotatedPoints[cc];
		result->y += projectionMatrix[1][cc] * rotatedPoints[cc];
		// printf("pm: %f, rotated: %f, result.x: %f\n", projectionMatrix[0][cc], rotatedPoints[cc], result->x);
		// printf("pm: %f, rotated: %f, result.y: %f\n", projectionMatrix[1][cc], rotatedPoints[cc], result->y);
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
	// printf("t_p x: %i, y: %i\n", point->x * s + o_x, point->y * s + o_y);
	point->x = nearbyintf(point->x * s + o_x);
	point->y = nearbyintf(point->y * s + o_y);
}

t_vec	*ft_calc_point(t_mlxinfo *info, int *cont)
{
	t_matrices	*matrices;
	float		*r_rot;
	t_vec		*r_proj;

	matrices = info->matrices;
	r_rot = ft_apply_rot(matrices->curr_rot_mat, cont);
	r_proj = ft_apply_proj(matrices->proj_mat, r_rot);
	free(r_rot);
	// printf("pre tp x: %i, y: %i\n", r_proj->x, r_proj->y);
	ft_transform_point(r_proj, info);
	// printf("after t_p x: %f, y: %f\n", r_proj->x, r_proj->y);
	return (r_proj);
}

void	ft_line(t_mlxinfo *info, t_vec *p0, t_vec *p1, int32_t color)
{
	// printf("line: x:%f, y:%f\n", p1->x, p1->y);
	// ft_transform_points(*p0, *p1, info);
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
		// printf("cntr: %i\n", cntr);
		// printf("result: x: %f y: %f\n", result->x, result->y);
		if (cont[cntr + 1])
		{
			result2 = ft_calc_point(info, cont[cntr + 1]);
			ft_line(info, result, result2, 0xFF00FFFF);
			// printf("result2: x: %f y: %f\n", result2->x, result2->y);
			free(result2);
		}
		if (head->next->content)
		{
			cont2 = ((int **)head->next->content);
			if (cont2[cntr+1])
			{
				
				result3 = ft_calc_point(info, cont2[cntr+1]);
				// printf("result3: x: %f y: %f\n", result3->x, result3->y);
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
		cleanup(info);
	cntr = 0;
	while (cntr < 2)
	{
		ft_bzero(pm[cntr] = malloc(3 * sizeof(float)), 3 * sizeof(float));
		if (!pm[cntr])
			cleanup(info);
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
