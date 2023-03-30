/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:44:41 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/29 19:22:52 by rnauke           ###   ########.fr       */
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

// uint32_t	ft_change_color(uint32_t c, uint32_t step)
// {	
// 	c += (step << 24);
// 	c += (step << 16);
// 	c += (step << 8);
// 	return (c);
// }

// uint32_t	ft_lc(uint32_t c1, uint32_t c2, int dx, int dy)
// {
// 	uint32_t	step_r;
// 	uint32_t	step_g;
// 	uint32_t	step_b;
// 	int			d;

// 	d = dx;
// 	if (abs(dy) > dx)
// 		d = dy;
// 	if (c1 == c2)
// 		return (c1);
// 	step_r = -(((c2 >> 24) & 0xff) - ((c1 >> 24) & 0xff)) / d;
// 	step_g = -(((c2 >> 16) & 0xff) - ((c1 >> 16) & 0xff)) / d;
// 	step_b = -(((c2 >> 8) & 0xff) - ((c1 >> 8)) & 0xff) / d;
// 	// printf("c1=%x, c2=%x, d=%i\n", c1, c2, d);
// 	return (((((c1 >> 24) & 0xff) + step_r) << 24) |
// 			((((c1 >> 16) & 0xff) + step_g) << 16) |
// 			((((c1 >> 8) & 0xff) + step_b) << 8) |
// 			(0xff));
// }

void	ft_plot_line(t_vec *p0, t_vec *p1, mlx_image_t *i)
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
		if (p0->x > 1 && p0->y > 1 && p0->x < i->height && p0->y < i->width)
			mlx_put_pixel (i, p0->x, p0->y, p1->c);
		if (p0->x == p1->x && p0->y == p1->y)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
			p0->x = step(&err, p0->x, p1->x, dy);
		if (e2 <= dx)
			p0->y = step(&err, p0->y, p1->y, dx);
	}
}
