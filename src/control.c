/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:27:14 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/30 17:01:58 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

void	ft_shmovin(t_mlxinfo *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_UP))
	{	
		info->pos_y -= 5;
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_DOWN))
	{	
		info->pos_y += 5;
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_LEFT))
	{	
		info->pos_x -= 5;
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_RIGHT))
	{	
		info->pos_x += 5;
		ft_connect_mesh(info);
	}
}

void	ft_zoom(t_mlxinfo *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_P))
	{	
		info->scale *= 1.05f;
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_O) && info->scale > 0.01f)
	{	
		info->scale *= 0.95f;
		ft_connect_mesh(info);
	}
}

void	ft_rot_p2(t_mlxinfo *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_S))
	{
		info->angle_x += .05f;
		ft_update_rot((void *)info);
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_W))
	{
		info->angle_x -= .05f;
		ft_update_rot((void *)info);
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_Q))
	{
		info->angle_z += .05f;
		ft_update_rot((void *)info);
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_E))
	{
		info->angle_z -= .05f;
		ft_update_rot((void *)info);
		ft_connect_mesh(info);
	}
}

void	ft_rot_control(t_mlxinfo *info)
{
	if (mlx_is_key_down(info->mlx, MLX_KEY_D))
	{
		info->angle_y += .05f;
		ft_update_rot((void *)info);
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_A))
	{
		info->angle_y -= .05f;
		ft_update_rot((void *)info);
		ft_connect_mesh(info);
	}
	ft_rot_p2(info);
}

void	ft_controls(void *param)
{
	t_mlxinfo	*info;

	info = param;
	if (mlx_is_key_down(info->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(info->mlx);
	if (mlx_is_key_down(info->mlx, MLX_KEY_G) && info->fl > info->xmax)
	{	
		info->fl -= 5;
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_F))
	{	
		info->fl += 5;
		ft_connect_mesh(info);
	}
	if (mlx_is_key_down(info->mlx, MLX_KEY_M))
	{	
		info->p = !info->p;
		ft_connect_mesh(info);
	}
	ft_shmovin(info);
	ft_zoom(info);
	ft_rot_control(info);
}
