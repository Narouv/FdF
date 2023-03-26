/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:55:03 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/08 15:39:25 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	convert_to_address(void *addy)
{
	char	*str;
	size_t	len;

	str = ft_ulltoah_printf((unsigned long long)addy);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}
