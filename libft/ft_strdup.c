/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:15:57 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/21 11:53:33 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
	{
	char	*dst;
	size_t	cntr;

	cntr = 0;
	dst = malloc(ft_strlen(s1)+1);
	if (!dst)
		return (NULL);
	while (*(s1 + cntr) != '\0' && cntr < ft_strlen(s1))
	{
		*(dst + cntr) = *(s1 + cntr);
		cntr++;
	}
	*(dst + cntr) = '\0';
	return (dst);
}
