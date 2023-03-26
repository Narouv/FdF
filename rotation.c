/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:50:20 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/25 18:58:00 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/FdF.h"

static float	**ft_rm(t_mlxinfo *info)
{
	int		cntr;
	float	**rm;

	rm = malloc(3 * sizeof(float *));
	if (!rm)
		cleanup(info);
	cntr = 0;
	while (cntr < 3)
	{
		rm[cntr] = malloc(3 * sizeof(float));
		if (!rm[cntr])
			cleanup(info);
		cntr++;
	}
	return (rm);
}

static float	*ft_trig(t_mlxinfo *info, float (*f)(float))
{
	float	*trig;

	trig = malloc(3 * sizeof(float));
	if (!trig)
		cleanup(info);
	trig[0] = f(info->angle_x);
	trig[1] = f(info->angle_y);
	trig[2] = f(info->angle_z);
	return (trig);
}

float	**ft_calc_rot(t_mlxinfo *info)
{
	float	**rm;
	float	*s;
	float	*c;

	s = ft_trig(info, sinf);
	c = ft_trig(info, cosf);
	rm = ft_rm(info);
	rm[0][0] = c[1] * c[2];
	rm[0][1] = s[0] * s[1] * c[2] - c[0] * s[2];
	rm[0][2] = c[0] * s[1] * c[2] + s[0] * s[2];
	rm[1][0] = c[1] * s[2];
	rm[1][1] = s[0] * s[1] * s[2] + c[0] * c[2];
	rm[1][2] = c[0] * s[1] * s[2] - s[0] * c[2];
	rm[2][0] = -s[1];
	rm[2][1] = s[0] * c[1];
	rm[2][2] = c[0] * c[1];
	return (rm);
}
