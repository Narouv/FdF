/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:24:37 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/07 15:36:40 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	cntr;

	if (!s || !f)
		return ;
	cntr = 0;
	while (cntr < ft_strlen(s))
	{
		f(cntr, s);
		cntr++;
	}
}
