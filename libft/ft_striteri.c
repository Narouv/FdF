/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:24:37 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 03:13:31 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	cntr;
	size_t	str_len;

	if (!s || !f)
		return ;
	str_len = ft_strlen(s);
	cntr = 0;
	while (cntr < str_len)
	{
		f(cntr, s + cntr);
		cntr++;
	}
}
