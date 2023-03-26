/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line->c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student->42heilbronn->de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:09:29 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/25 19:56:10 by rnauke           ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

int	step(int *err, int dir0, int dir1, int d_dir)
{
	int	step;

	step = -1;
	if (dir0 < dir1)
		step = 1;
	*err += d_dir;
	dir0 += step;
	return (dir0);
}

void	ft_plot_line(t_vec *p0, t_vec *p1, mlx_image_t *image, int32_t color)
{
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = abs ((int)p1->x - (int)p0->x);
	dy = -abs ((int)p1->y - (int)p0->y);
	err = dx + dy;
	while (1)
	{
		if (p0->x > 1 && p0->y > 1 && p0->x < image->height && p0->y < image->width)
			mlx_put_pixel (image, p0->x, p0->y, color);
		if (p0->x == p1->x && p0->y == p1->y)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
			p0->x = step(&err, p0->x, p1->x, dy);
		if (e2 <= dx)
			p0->y = step(&err, p0->y, p1->y, dx);
	}
}
