/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:35:29 by pgorner           #+#    #+#             */
/*   Updated: 2023/03/27 17:20:28 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next(char *buf)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		++i;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	res = ft_calloc((ft_strlen(buf) - i + 1), sizeof(char));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != '\0')
		res[j++] = buf[i++];
	free(buf);
	return (res);
}

char	*ft_line(char *buf)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		++i;
	res = ft_calloc(i + 2, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		res[i] = buf[i];
		++i;
	}
	if (buf[i] == '\n')
		res[i] = '\n';
	buf = res;
	return (buf);
}

char	*ft_read(int fd, char *buf)
{
	char	*str;
	int		byte;

	if (!buf)
		buf = ft_calloc(1, 1);
	if (!buf)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (byte >= 1)
	{
		ft_bzero(str, BUFFER_SIZE + 1);
		byte = read(fd, str, BUFFER_SIZE);
		if (byte == -1)
			return (free(buf), free(str), NULL);
		buf = ft_strjoinfr(buf, str);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (free(str), buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_line(buf);
	buf = ft_next(buf);
	return (line);
}
