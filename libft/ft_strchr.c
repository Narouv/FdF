/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:15:57 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/27 01:51:56 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	cntr;

	cntr = 0;
	while (*(s + cntr) != (char)c)
	{
		if (*(s + cntr) == '\0' && c != '\0')
		{
			return (NULL);
		}
		cntr++;
	}
	return ((char *)s + cntr);
}
