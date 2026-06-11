/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:56:52 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 09:56:56 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_memory(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

static int	is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	count_words(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_whitespace(*s))
			s++;
		if (*s)
			count++;
		while (*s && !is_whitespace(*s))
			s++;
	}
	return (count);
}

static int	allocate_memory(char **str, char const *s)
{
	size_t		i;
	char const	*start;

	i = 0;
	while (*s)
	{
		while (*s && is_whitespace(*s))
			s++;
		start = s;
		while (*s && !is_whitespace(*s))
			s++;
		if (s > start)
		{
			str[i] = ft_substr(start, 0, s - start);
			if (!str[i])
				return (free_memory(str, i), 0);
			i++;
		}
	}
	str[i] = NULL;
	return (1);
}

char	**split_by_whitespace(const char *s)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s) + 1));
	if (!str)
		return (NULL);
	if (!allocate_memory(str, s))
		return (NULL);
	return (str);
}
