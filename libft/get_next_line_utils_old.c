/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:53:27 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/21 19:03:26 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_realloc(char *ptr, size_t add	)
{
	int		len;
	char	*new_ptr;

	len = ft_strlen(ptr);
	new_ptr = malloc(len + add);
	ft_strlcpy(new_ptr, ptr, len + add);
	free(ptr);
	ptr = NULL;
	return (new_ptr);
}

char	*ft_check_line(char *line, char *l_buf)
{
	size_t	cntr;
	size_t	len;

	cntr = 0;
	len = 0;
	if (*line)
	{
		while (*(line + cntr))
		{	
			if (*(line + cntr) == '\n')
			{
				cntr++;
				while (*(line + cntr) + len != '\0')
					len++;
				ft_strlcpy(l_buf, line + cntr, len + 1);
				*(line + cntr) = '\0';
				return (line);
			}
			cntr++;
		}
		return (line);
	}
	free(line);
	return (NULL);
}
