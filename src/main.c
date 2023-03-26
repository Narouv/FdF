/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:38:39 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/26 16:30:42 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void ft_clear_screen(void *param)
{
	mlx_image_t	*image;

	image = param;
	for (uint32_t i = 0; i < image->width; ++i)
		for (uint32_t y = 0; y < image->height; ++y)
			mlx_put_pixel(image, i, y, 0x000000FF);
}

// void ft_connect_line(t_mlxinfo info, t_list head)
// {
// 	int	**cont;
// 	int cntr;
	
// 	cont = head->content;
// 	cntr = 0;
// 	while (cont[cntr])
// 	{
// 		result = ft_apply_proj(proj_matrix, ft_apply_rot(iso_matrix, cont[cntr]));
// 		if (cont[cntr + 1])
// 		{
// 			result2 = ft_apply_proj(proj_matrix, ft_apply_rot(iso_matrix, cont[cntr + 1]));
// 			ft_plot_line(nearbyintf(result[0]*s+WIDTH/2), nearbyintf(result[1]*s+HEIGHT/4+100), nearbyintf(result2[0]*s+WIDTH/2), nearbyintf(result2[1]*s+HEIGHT/4+100), info->image);
// 		}
// 		if (head->next->content)
// 		{
// 			if (((int **)head->next->content)[cntr])
// 				result2 = ft_apply_proj(proj_matrix, ft_apply_rot(iso_matrix, ((int **)head->next->content)[cntr]));
// 			ft_plot_line(nearbyintf(result[0]*s+WIDTH/2), nearbyintf(result[1]*s+HEIGHT/4+100), nearbyintf(result2[0]*s+WIDTH/2), nearbyintf(result2[1]*s+HEIGHT/4+100), info->image);
// 		}
// 		cntr++;
// 	}
// }

void	ft_connect_mesh(void *param)
{
	t_mlxinfo	*info;
	t_list		*head;

	info = param;
	head = info->matrices->object_points;
	while (head->next)
	{
		ft_connect_line(info, head);
		head = head->next;
	}
}

void ft_controls(void* param)
{
	t_mlxinfo *info;

	info = param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_UP))
		info->pos_y -= 5;
	if (mlx_is_key_down(info->mlx, MLX_KEY_DOWN))
		info->pos_y += 5;
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
		info->pos_x -= 5;
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
		info->pos_x += 5;
	if (mlx_is_key_down(info->mlx, MLX_KEY_P))
		info->scale += 0.1f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_O) && info->scale > 0.1f)
		info->scale -= 0.1f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
		info->angle_y += .1f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
		info->angle_y -= .1f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
		info->angle_x += .1f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
		info->angle_x -= .1f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_Q))
		info->angle_z += .1f;
	if (mlx_is_key_down(info->mlx, MLX_KEY_E))
		info->angle_z -= .1f;
}

int	ft_split_size(char **split)
{
	int	cntr;
	
	cntr = 0;
	while (split[cntr])
		cntr++;
	return (cntr);
}

int	**ft_create_object(char **split, t_mlxinfo *info, int index)
{
	int	cntr;
	int	*point;
	int **point_list;
	
	cntr = ft_split_size(split) + 1;
	ft_bzero(point_list = malloc(cntr*sizeof(int *)), cntr*sizeof(int *));
	if (!point_list)
			cleanup(info, "point list alloc fail");
	cntr = 0;
	while (split[cntr])
	{
		point = malloc(3*sizeof(int));
		if (!point)
			cleanup(info, "3d point alloc fail");
		point[0] = cntr * 10;
		point[1] = ft_atoi(split[cntr]);
		point[2] = index * 10;
		point_list[cntr++] = point;
	}
	point_list[cntr] = NULL;
	while (cntr > -1)
		free(split[cntr--]);
	return (point_list);
}

void	ft_read_input_file(char *path, t_mlxinfo *info)
{
	int fd;
	char *read;
	int i;
	t_list *head;

	head = info->matrices->object_points;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	i = 0;
	read = get_next_line(fd);
	while (read)
	{
		ft_lstadd_front(&head, ft_lstnew((void*)ft_create_object(ft_split(read, ' '), info, i)));
		free(read);
		i++;
		read = get_next_line(fd);
	}
	free(read);
	info->matrices->object_points = head;
}

mlx_t	*ft_init_mlx(t_mlxinfo *info)
{
	mlx_t				*mlx;
	static mlx_image_t	*image;
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "FdF", true)))
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	info->image = image;
	if (mlx_image_to_window(mlx, info->image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	return (mlx);
}

// float iso_matrix[3][3] = {
// 		{ cos(45), 0, -sin(45) },
// 		{ -0.55237, -0.76065, -0.34101 },
// 		{ -0.64724, 0.64916, -0.39958 }
// 	};

// 	float proj_matrix[2][3] = { 
// 		{ 1, 0, 0 },
// 		{ 0, 1, 0 },
// 	};

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

void	ft_update_rot(void *param)
{
	t_mlxinfo	*info;
	
	info = param;
	ft_calc_rot(info);
}

t_mlxinfo	*ft_init_info()
{
	t_mlxinfo *info;

	info = malloc(sizeof(t_mlxinfo));
	if (!info)
		cleanup(info, "info struct alloc fail");
	info->matrices = malloc(sizeof(t_matrices));
	if (!info->matrices)
		cleanup(info, "matrices struct alloc fail");
	info->matrices->object_points = ft_lstnew(NULL);
	info->scale = 2.f;
	info->angle_x = 0.f;
	info->angle_y = 0.f;
	info->angle_z = 0.f;
	info->pos_x = WIDTH/2; 
	info->pos_y = HEIGHT/2;
	info->matrices->proj_mat = ft_projection(info);
	info->matrices->curr_rot_mat = ft_rm(info);
	ft_update_rot(info);
	return (info);
}

void checkleaks()
{
	system("leaks fdf");
}

int	main(int argc, const char* argv[])
{
	t_mlxinfo	*info;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <.fdf file path>");
		exit(EXIT_FAILURE);
	}
	info = ft_init_info();
	info->mlx = ft_init_mlx(info);
	ft_read_input_file((char *)argv[1], info);
	ft_printf("running\n");
	mlx_loop_hook(info->mlx, ft_clear_screen, info->image);
	mlx_loop_hook(info->mlx, ft_connect_mesh, info);
	mlx_loop_hook(info->mlx, ft_controls, info);	
	mlx_loop_hook(info->mlx, ft_update_rot, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);
	cleanup(info, NULL);
	return (EXIT_SUCCESS);
}
