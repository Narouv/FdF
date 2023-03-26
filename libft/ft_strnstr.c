/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:15:57 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 02:02:38 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cmp(const char *haystack, const char *needle, size_t len)
{
	size_t	cntr_n;
	size_t	cntr_h;

	cntr_h = 0;
	cntr_n = 0;
	while (*(haystack + cntr_h) == *(needle + cntr_n) && cntr_h < len)
	{
		if (!*(haystack + cntr_h))
			break ;
		cntr_n++;
		cntr_h++;
	}
	return (cntr_n);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cntr_hay;
	size_t	cntr_needle;

	cntr_needle = 0;
	cntr_hay = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (cntr_hay < len && *(haystack + cntr_hay))
	{
		cntr_needle = ft_cmp(haystack + cntr_hay, needle, len - cntr_hay);
		if (cntr_needle == ft_strlen(needle))
			return ((char *)haystack + cntr_hay);
		cntr_hay++;
	}
	return (NULL);
}
