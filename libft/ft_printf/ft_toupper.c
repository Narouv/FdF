/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:28:22 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/07 15:38:13 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c < 'a' || c > 'z')
	{
		return (c);
	}
	return ((unsigned char)c - 0x20);
}
