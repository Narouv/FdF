/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:30:17 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 02:32:11 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat_str;
	size_t	cntr;

	if (!s1 || !s2)
		return (NULL);
	cntr = 0;
	cat_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!cat_str)
		return (NULL);
	while ((cntr < ft_strlen(s1) || cntr < ft_strlen(s2)))
	{
		if (cntr < ft_strlen(s1))
		{
			*(cat_str + cntr) = *(s1 + cntr);
		}
		if (cntr < ft_strlen(s2))
		{
			*(cat_str + ft_strlen(s1) + cntr) = *(s2 + cntr);
		}
		cntr++;
	}
	*(cat_str + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (cat_str);
}
