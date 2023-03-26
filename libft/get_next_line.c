/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:53:29 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/19 21:09:30 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_check_nl(char *line)
{
	size_t	cntr;

	cntr = 0;
	while (*(line + cntr))
	{	
		if (*(line + cntr) == '\n')
		{
			return (cntr + 1);
		}
		cntr++;
	}
	return (0);
}

char	*ft_from_buffer(char *line, char *l_buf, size_t *cntr)
{
	if (*l_buf)
	{
		ft_bzero(l_buf, ft_strlcpy(line, l_buf, ft_strlen(l_buf) + 1));
		line = ft_char_realloc(line, BUFFER_SIZE);
		*cntr = ft_strlen(line);
	}
	return (line);
}

char	*get_line(char *line, char *line_buf, size_t nl_pos)
{
	ft_strlcpy(line_buf, line + nl_pos, ft_strlen(line + nl_pos) + 1);
	*(line + nl_pos) = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	size_t		cntr;
	char		*line;
	static char	line_buf[10240][BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	size_t		nl_pos;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cntr = 0;
	bytes_read = 0;
	ft_bzero(line = malloc(BUFFER_SIZE + 1), BUFFER_SIZE + 1);
	line = ft_from_buffer(line, line_buf[fd], &cntr);
	while (1)
	{
		nl_pos = ft_check_nl(line);
		if (nl_pos)
			return (get_line(line, line_buf[fd], nl_pos));
		bytes_read = read(fd, line + cntr, BUFFER_SIZE);
		if ((bytes_read < 1))
			return (ft_check_line(line, line_buf[fd]));
		*(line + cntr + bytes_read) = '\0';
		cntr += bytes_read;
		line = ft_char_realloc(line, BUFFER_SIZE + 1);
	}
}
