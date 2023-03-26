/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:15:57 by rnauke            #+#    #+#             */
/*   Updated: 2022/05/27 01:52:19 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	cntr;

	cntr = ft_strlen(s);
	while (cntr >= 0)
	{
		if (*(s + cntr) == (char)c)
		{
			return ((char *)s + cntr);
		}
		cntr--;
	}
	return (NULL);
}
