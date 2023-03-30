/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:38:39 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/29 19:38:22 by rnauke           ###   ########.fr       */
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

void	ft_update_rot(void *param)
{
	t_mlxinfo	*info;

	info = param;
	ft_calc_rot(info);
}

int	ft_split_size(char **split, t_mlxinfo *info)
{
	int	cntr;

	cntr = 0;
	while (split[cntr])
		cntr++;
	info->xmax = cntr * 10;
	info->fl = info->xmax * 1.5;
	info->pos_x = 50 + (info->xmax % (WIDTH / 4));
	return (cntr);
}

uint32_t	hex2int(char *hex)
{
	uint32_t	val;
	uint8_t		byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

int	ft_get_color(char *s)
{
	char	*c;
	
	c = ft_strchr(s, ',');
	if (c)
		return ((hex2int(c + 3) << 8) + 0xFF);
	else
		return (0xFFFFFFFF);
}

int	**ft_co(char **split, t_mlxinfo *info, int index)
{
	int	cntr;
	int	*point;
	int	**point_list;

	cntr = ft_split_size(split, info);
	point_list = malloc(cntr * sizeof(int *));
	if (!point_list)
		cleanup(info, "point list alloc fail");
	cntr = 0;
	while (split[cntr])
	{
		point = malloc(4 * sizeof(int));
		if (!point)
			cleanup(info, "3d point alloc fail");
		point[0] = cntr * 10;
		point[1] = ft_atoi(split[cntr]);
		point[2] = index * 10;
		point[3] = ft_get_color(split[cntr]);
		point_list[cntr++] = point;
	}
	point_list[cntr] = NULL;
	while (cntr >= 0)
		free(split[cntr--]);
	free(split);
	return (point_list);
}

void	ft_read_input_file(int fd, t_mlxinfo *info)
{
	char	*read;
	int		i;
	t_list	*head;

	head = info->matrices->object_points;
	i = 0;
	read = get_next_line(fd);
	while (read)
	{
		ft_lstadd_front(&head, ft_lstnew(ft_co(ft_split(read, ' '), info, i)));
		free(read);
		i++;
		read = get_next_line(fd);
	}
	free(read);
	info->matrices->object_points = head;
	info->ymax = i;
	info->scale = HEIGHT / info->ymax / 10.f;
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
	// mlx image to window creates ROOT CYCLE leak ?
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	return (mlx);
}

float	**ft_rm(t_mlxinfo *info)
{
	int		cntr;
	float	**rm;

	rm = malloc(3 * sizeof(float *));
	if (!rm)
		cleanup(info, "rm alloc fail");
	cntr = 0;
	while (cntr < 3)
	{
		rm[cntr] = malloc(3 * sizeof(float));
		if (!rm[cntr])
			cleanup(info, "rm cntr alloc fail");
		cntr++;
	}
	return (rm);
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
	info = ft_init_info();
	info->mlx = ft_init_mlx(info);
	ft_read_input_file(fd, info);
	close(fd);
	ft_printf("running\n");
	ft_connect_mesh(info);
	// mlx_loop_hook(info->mlx, ft_clear_screen, info->image);
	// mlx_loop_hook(info->mlx, ft_connect_mesh, info);
	mlx_loop_hook(info->mlx, ft_controls, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);
	cleanup(info, NULL);
	return (EXIT_SUCCESS);
}
