/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:14:22 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 02:01:45 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dst_address;
	const char	*src_address;
	size_t		len;
	size_t		dst_len;

	dst_address = dst;
	src_address = src;
	len = dstsize;
	while (len-- && *dst)
		dst++;
	dst_len = dst - dst_address;
	len = dstsize - dst_len;
	if (len == 0)
		return (dst_len + ft_strlen(src));
	while (*src)
	{
		if (len != 1)
		{
			*dst++ = *src;
			len--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_len + (src - src_address));
}
