/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:09:02 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/08 14:31:32 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_int_len(unsigned long long n)
{
	int	len;

	len = 0LL;
	if (n < 0LL)
		len++;
	n /= 10LL;
	len++;
	while (n)
	{
		n /= 10LL;
		len++;
	}
	return (len);
}

char	*ft_itoa_printf(unsigned long long n)
{
	int		cntr;
	char	*str;

	cntr = ft_get_int_len(n);
	str = malloc(cntr + 1 * sizeof(char));
	if (!str)
		return ((char *) NULL);
	*(str + cntr--) = '\0';
	while ((cntr >= 0LL || n) && str)
	{
		*(str + cntr) = (n % 10LL) + 0x30LL;
		n /= 10LL;
		cntr--;
	}
	return (str);
}
