/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:15:10 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/30 16:24:03 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FdF.h"

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

	cntr = ft_split_size(split, info) + 1;
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
	// info->scale = HEIGHT / info->ymax / 5.f;
}
