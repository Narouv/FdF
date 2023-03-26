/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:41:00 by rnauke            #+#    #+#             */
/*   Updated: 2022/04/16 14:49:29 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	n /= 10;
	len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_convert_to_str(char *str, int cntr, int n)
{
	if (n < 0)
	{
		*(str + cntr) = ((n % 10) * -1) + 0x30;
		n *= -1;
	}
	else
		*(str + cntr) = (n % 10) + 0x30;
}

char	*ft_itoa(int n)
{
	int		cntr;
	short	negative;
	char	*str;

	negative = 0;
	cntr = ft_get_int_len(n);
	str = malloc(cntr + 1 * sizeof(char));
	if (!str)
		return ((char *) NULL);
	*(str + cntr--) = '\0';
	if (n < 0)
		negative = 1;
	while ((cntr >= 0 || n) && str)
	{
		ft_convert_to_str(str, cntr, n);
		n /= 10;
		cntr--;
	}
	if (negative && str)
		*str = '-';
	return (str);
}
