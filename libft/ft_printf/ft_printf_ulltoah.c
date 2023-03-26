/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ulltoah.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:36:38 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/08 15:38:19 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_int_len(unsigned long long n)
{
	int	len;

	len = 0ULL;
	if (n < 0)
		len++;
	n /= 16ULL;
	len++;
	while (n)
	{
		n /= 16ULL;
		len++;
	}
	return (len);
}

char	*ft_ulltoah_printf(unsigned long long n)
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
		if ((n % 16ULL) < 10ULL)
			*(str + cntr) = (n % 16ULL) + 48ULL;
		else
			*(str + cntr) = (n % 16ULL) + 87ULL;
		n /= 16ULL;
		cntr--;
	}
	return (str);
}
