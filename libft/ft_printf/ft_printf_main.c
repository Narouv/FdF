/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:49:39 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/09 16:05:08 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	replace_specifiers(char *str, va_list vargs)
{
	if (*str == '%')
		return (percent_sign());
	if (*str == 'i' || *str == 'd')
		return (convert_to_decimal(va_arg(vargs, int)));
	if (*str == 'p')
		return (convert_to_address(va_arg(vargs, void *)));
	if (*str == 'c')
		return (convert_to_char(va_arg(vargs, int)));
	if (*str == 's')
		return (convert_to_string(va_arg(vargs, char *)));
	if (*str == 'u')
		return (convert_to_uint(va_arg(vargs, unsigned int)));
	if (*str == 'x')
		return (convert_to_hex_lowercase(va_arg(vargs, size_t)));
	if (*str == 'X')
		return (convert_to_hex_uppercase(va_arg(vargs, size_t)));
	return (0);
}

static int	get_print_len(char *str)
{
	int	cntr;

	cntr = 0;
	while (*str)
	{
		if (*str == '%')
			str++;
		else
			cntr++;
		if (str)
			str++;
	}
	return (cntr);
}

int	ft_printf(const char *str, ...)
{
	size_t	cntr;
	size_t	str_len;
	va_list	vargs;

	cntr = 0;
	str_len = get_print_len((char *)str);
	va_start(vargs, str);
	while (cntr < ft_strlen(str))
	{
		if (*(str + cntr) == '%')
		{
			str_len += replace_specifiers((char *)(str + cntr + 1), vargs);
			cntr += 2;
		}
		else
		{
			ft_putchar_fd(*(str + cntr), 1);
			cntr++;
		}
	}
	va_end(vargs);
	return (str_len);
}
