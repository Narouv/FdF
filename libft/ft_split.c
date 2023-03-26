/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnauke <rnauke@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:31:33 by rnauke            #+#    #+#             */
/*   Updated: 2023/03/19 21:43:19 by rnauke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//this function returns the amount of char c in string str
static size_t	ft_words(const char *str, int c)
{
	size_t	cntr;
	size_t	words;

	cntr = 0;
	words = 0;
	if (*str != c && *str)
		words++;
	while (*(str + cntr) != '\0')
	{
		if (*(str + cntr) == c && *(str + cntr + 1) != c && *(str + cntr + 1))
		{
			words++;
		}
		cntr++;
	}
	return (words);
}

void	*ft_free_array(char **array, int size)
{
	while (size--)
	{
		free(*(array + size));
	}
	free(array);
	return (NULL);
}

static size_t	ft_get_malloc_size(char *s, char c)
{
	size_t	cntr;

	cntr = 0;
	while (*s != c && *s)
	{
		cntr++;
		s++;
	}
	return (cntr);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**str_arr;
	size_t	words;

	if (!s)
		return (NULL);
	index = 0;
	words = ft_words(s, c);
	str_arr = malloc((words + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	while (index < words)
	{
		while (*s == c)
			s++;
		if (ft_get_malloc_size((char *)s, c))
			*(str_arr + index) = malloc(ft_get_malloc_size((char *)s, c) + 1);
		if (!*(str_arr + index))
			return (ft_free_array(str_arr, index));
		ft_strlcpy(*(str_arr + index), s, ft_get_malloc_size((char *)s, c) + 1);
		s += ft_get_malloc_size((char *)s, c);
		index++;
	}
	*(str_arr + index) = NULL;
	return (str_arr);
}
