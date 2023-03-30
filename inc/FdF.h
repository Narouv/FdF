/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:09:29 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/30 16:20:48 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

#define WIDTH 1024
#define HEIGHT 1024

typedef struct s_vec
{
	float		x;
	float		y;
	uint32_t	c;
}				t_vec;

/**
 * Struct contains all matrices needed for 3d projection.
 * @param proj_mat Projection matrix.
 * @param object_points All points of a 3d-Object.
 * @param current_point The point to be rendered next frame.
 */
typedef struct s_matrices
{
	float	**curr_rot_mat;
	float	**proj_mat;
	t_list	*object_points;
}			t_matrices;

/**
 * Struct for all the context I might need for doing anything.
 * Contains information about mlx + everything needed to manipulate wireframes.
 * 
 * @param mlx The mlx handle.
 * @param mlx_image The mlx_image handle.
 * @param x Position of the image on the x-axis.
 * @param y Position of the image on the y-axis.
 * @param scale Scale of the rendered object/How close the camera is to object.
 * @param x_offset x-position of the object in the image.
 * @param y_offset y-position of the object in the image.
 */
typedef struct s_mlxinfo
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			pos_x;
	int			pos_y;
	float		scale;
	t_matrices	*matrices;
	float		angle_x;
	float		angle_y;
	float		angle_z;
	int			fl;
	int			p;
	int			xmax;
	int			ymax;
}				t_mlxinfo;

// matrix.c
t_vec		*ft_apply_proj(t_mlxinfo *info, float **pm, float *rp);
t_vec		*ft_apply_wp(t_mlxinfo *info, float *rotatedPoints);
float		*ft_apply_rot(t_mlxinfo *info, float **rotationMatrix, int *vertex);

// line.c
void		ft_plot_line(t_vec *p0, t_vec *p1, mlx_image_t *image);

// cleanup.c
void		cleanup(t_mlxinfo *info, char *msg);

// projection.c
void		ft_connect_line(t_mlxinfo *info, t_list *head);
float		**ft_calc_rot(t_mlxinfo *info);
float		**ft_projection(t_mlxinfo *info);

// control.c
void		ft_controls(void *param);
void		ft_rot_control(t_mlxinfo *info);
void		ft_zoom(t_mlxinfo *info);
void		ft_shmovin(t_mlxinfo *info);

// rotation.c
float		**ft_rm(t_mlxinfo *info);
void		ft_update_rot(void *param);

// model.c
uint32_t	hex2int(char *hex);
int			ft_get_color(char *s);
int			**ft_co(char **split, t_mlxinfo *info, int index);
void		ft_read_input_file(int fd, t_mlxinfo *info);
int			ft_split_size(char **split, t_mlxinfo *info);

// main.c
void		ft_update_rot(void *param);
void		ft_connect_mesh(void *param);

#endif
