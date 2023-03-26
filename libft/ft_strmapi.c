/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:31:30 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 03:13:22 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	cntr;
	char	*new_str;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	cntr = 0;
	new_str = malloc((ft_strlen(s) + 1));
	while (cntr < strlen && new_str)
	{
		*(new_str + cntr) = f(cntr, *(s + cntr));
		cntr++;
	}
	if (new_str)
		*(new_str + cntr) = '\0';
	return (new_str);
}
