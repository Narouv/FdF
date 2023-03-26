/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:12:35 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/09 15:59:18 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	to_upper(unsigned int i, char *c)
{
	*(c + i) = ft_toupper(*(c + i));
}

size_t	convert_to_hex_lowercase(size_t l_hex)
{
	char	*str;
	size_t	len;

	str = ft_itoah_printf(l_hex);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

size_t	convert_to_hex_uppercase(size_t u_hex)
{
	char	*str;
	size_t	len;

	str = ft_itoah_printf(u_hex);
	ft_striteri(str, to_upper);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
