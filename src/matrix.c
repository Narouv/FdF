/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:19:03 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/30 16:58:45 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int	ft_split_size(char **split, t_mlxinfo *info)
{
	int	cntr;

	cntr = 0;
	while (split[cntr])
		cntr++;
	info->xmax = cntr * 10;
	info->fl = info->xmax * 3;
	info->pos_x = 50 + (info->xmax % (WIDTH / 4));
	return (cntr);
}

float	*ft_apply_rot(t_mlxinfo *info, float **rotationMatrix, int *vertex)
{
	float	*result;
	int		cc;

	ft_bzero(result = malloc(4 * sizeof(float)), 4 * sizeof(float));
	if (!result)
		cleanup(info, "apply rot alloc fail");
	cc = 0;
	while (cc < 3)
	{
		result[0] += rotationMatrix[0][cc] * vertex[cc];
		result[1] += rotationMatrix[1][cc] * vertex[cc];
		result[2] += rotationMatrix[2][cc] * vertex[cc];
		cc++;
	}
	result[3] = vertex[3];
	return (result);
}

t_vec	*ft_apply_wp(t_mlxinfo *info, float *rotatedPoints)
{
	t_vec	*result;

	ft_bzero(result = malloc(sizeof(t_vec)), sizeof(t_vec));
	if (!result)
		cleanup(info, "apply rot alloc fail");
	result->x = (info->fl * rotatedPoints[0]) / (info->fl + rotatedPoints[2]);
	result->y = (info->fl * rotatedPoints[1]) / (info->fl + rotatedPoints[2]);
	result->c = rotatedPoints[3];
	return (result);
}

t_vec	*ft_apply_proj(t_mlxinfo *info, float **pm, float *rp)
{
	t_vec	*result;
	int		cc;

	ft_bzero(result = malloc(sizeof(t_vec)), sizeof(t_vec));
	if (!result)
		cleanup(info, "apply rot alloc fail");
	cc = 0;
	while (cc < 3)
	{
		result->x += pm[0][cc] * rp[cc];
		result->y += pm[1][cc] * rp[cc];
		cc++;
	}
	result->c = rp[3];
	return (result);
}
