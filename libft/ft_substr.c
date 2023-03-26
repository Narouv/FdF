/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:29:40 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 01:59:26 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	cntr;

	if (!s)
		return (NULL);
	cntr = 0;
	if (ft_strlen(s) > len)
		sub_str = malloc(len + 1);
	else
		sub_str = malloc(ft_strlen(s + start) + 1);
	if (!sub_str || !s)
		return (NULL);
	while (*(s + cntr) != '\0' && cntr < len)
	{
		if (ft_strlen(s) < start)
			break ;
		*(sub_str + cntr) = *(s + start + cntr);
		cntr++;
	}
	*(sub_str + cntr) = '\0';
	return (sub_str);
}
