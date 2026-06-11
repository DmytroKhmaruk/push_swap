/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 23:55:43 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 17:12:16 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_memory(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

static int	count_words(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			count++;
		while (*s && *s != sep)
			s++;
	}
	return (count);
}

static int	allocate_memory(char **str, char const *s, char sep)
{
	size_t		i;
	char const	*start;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		start = s;
		while (*s && *s != sep)
			s++;
		if (s > start)
		{
			str[i] = ft_substr(start, 0, s - start);
			if (!str[i])
			{
				free_memory(str, i);
				return (0);
			}
			i++;
		}
	}
	str[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (NULL);
	if (!allocate_memory(str, s, c))
		return (NULL);
	return (str);
}
/*
#include <stdio.h>

static void	print_and_free(char **result)
{
	size_t	i;

	if (!result)
	{
		printf("NULL\n");
		return ;
	}
	i = 0;
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	free_memory(result, i);
	printf("-------\n");
}

int	main(void)
{
	print_and_free(ft_split("", ' '));
	print_and_free(ft_split("   ", ' '));
	print_and_free(ft_split("Hello", ' '));
	print_and_free(ft_split("  Hello   Universe  ", ' '));
	print_and_free(ft_split("Hello,Universe,From,Galaxy", ','));
	print_and_free(ft_split(NULL, ' '));

	return (0);
}
*/
