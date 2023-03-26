/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:29:10 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 02:20:53 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_chars(char c)
{
	if ((!ft_isprint(c) && c != 45 && c != 43 && c > 0 && c != 27) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	cntr;
	int		num;

	num = 0;
	cntr = 0;
	while (ft_check_chars(*str))
		str++;
	if (*str == '-' || *str == '+')
		cntr++;
	if (!ft_isdigit(*(str + cntr)))
		return (0);
	while (cntr < ft_strlen(str))
	{
		if (!ft_isdigit(*(str + cntr)))
			break ;
		num *= 10;
		num += (int)(*(str + cntr) - 0x30);
		cntr++;
	}
	if (*str == '-')
		num *= -1;
	return (num);
}
