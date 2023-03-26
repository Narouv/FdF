/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoah.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:45:18 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/09 16:02:40 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_int_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	n /= 16;
	len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoah_printf(unsigned int n)
{
	int		cntr;
	char	*str;

	cntr = ft_get_int_len(n);
	str = malloc(cntr + 1 * sizeof(char));
	if (!str)
		return ((char *) NULL);
	*(str + cntr--) = '\0';
	while ((cntr >= 0 || n) && str)
	{
		if ((n % 16) < 10)
			*(str + cntr) = (n % 16) + 48;
		else
			*(str + cntr) = (n % 16) + 87;
		n /= 16;
		cntr--;
	}
	return (str);
}
