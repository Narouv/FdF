/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:38:39 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/30 16:51:21 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	ft_clear_screen(void *param)
{
	mlx_image_t	*image;
	uint32_t	i;
	uint32_t	y;

	image = param;
	i = 0;
	while (i < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			mlx_put_pixel(image, i, y, 0x000000FF);
			y++;
		}
		i++;
	}
}

void	ft_connect_mesh(void *param)
{
	t_mlxinfo	*info;
	t_list		*head;

	info = param;
	head = info->matrices->object_points;
	ft_clear_screen(info->image);
	while (head->next)
	{
		ft_connect_line(info, head);
		head = head->next;
	}
}

mlx_t	*ft_init_mlx(t_mlxinfo *info)
{
	mlx_t				*mlx;
	static mlx_image_t	*image;

	mlx = mlx_init(WIDTH, HEIGHT, "FdF", true);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	info->image = image;
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	return (mlx);
}

t_mlxinfo	*ft_init_info(void)
{
	t_mlxinfo	*info;

	info = malloc(sizeof(t_mlxinfo));
	if (!info)
		cleanup(info, "info struct alloc fail");
	info->matrices = malloc(sizeof(t_matrices));
	if (!info->matrices)
		cleanup(info, "matrices struct alloc fail");
	info->matrices->object_points = ft_lstnew(NULL);
	info->scale = 3.f;
	info->angle_x = 3.6f;
	info->angle_y = .4f;
	info->angle_z = 0.1f;
	info->pos_x = 50;
	info->pos_y = 50;
	info->matrices->proj_mat = ft_projection(info);
	info->matrices->curr_rot_mat = ft_rm(info);
	info->fl = 500;
	info->p = 0;
	info->xmax = 0;
	info->ymax = 0;
	ft_update_rot(info);
	return (info);
}

int	main(int argc, const char *argv[])
{
	t_mlxinfo	*info;
	int			fd;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <.fdf file path>");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("enter valid file");
		exit(EXIT_FAILURE);
	}
	info = ft_init_info();
	info->mlx = ft_init_mlx(info);
	ft_read_input_file(fd, info);
	close(fd);
	ft_connect_mesh(info);
	mlx_loop_hook(info->mlx, ft_controls, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);
	cleanup(info, NULL);
	return (EXIT_SUCCESS);
}
