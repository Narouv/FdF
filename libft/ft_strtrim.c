/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:30:45 by rnauke            #+#    #+#             */
/*   Updated: 2022/06/01 02:04:56 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_str_begin(char *s1, char *set, size_t setsize)
{
	size_t	set_cntr;
	size_t	cntr;

	set_cntr = 0;
	cntr = 0;
	while (1)
	{
		if (*(s1 + cntr) == *(set + set_cntr) && *(set + set_cntr))
		{
			cntr++;
			set_cntr = 0;
			continue ;
		}
		if (set_cntr == setsize)
			break ;
		set_cntr++;
	}
	return (s1 + cntr);
}

static size_t	ft_set_end(const char *s1end, const char *set, size_t setsize)
{
	size_t	set_cntr;
	int		cntr;

	set_cntr = 0;
	cntr = 0;
	while (1)
	{
		if (*(s1end - cntr) == *(set + set_cntr) && *(set + set_cntr))
		{
			cntr++;
			set_cntr = 0;
			continue ;
		}
		if (set_cntr == setsize)
			break ;
		set_cntr++;
	}
	return (cntr);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str_result;
	char	*tmp_str;
	int		end_cntr;

	end_cntr = 0;
	if (!s1 || !set)
		return (NULL);
	tmp_str = ft_get_str_begin((char *)s1, (char *)set, ft_strlen(set));
	if (ft_strlen(tmp_str))
		end_cntr = ft_set_end(s1 + ft_strlen(s1) - 1, set, ft_strlen(set));
	str_result = malloc(ft_strlen(tmp_str) - end_cntr + 1);
	if (!str_result)
		return (NULL);
	ft_strlcpy(str_result, tmp_str, ft_strlen(tmp_str) - end_cntr + 1);
	return (str_result);
}
