/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:41:15 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/01 17:26:03 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static char	**ft_free(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

static char	*ft_get_w(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static int	ft_count_w(char const *s, char c)
{
	int	i;
	int	in_w;
	int	words;

	i = 0;
	in_w = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && in_w == 0)
		{
			in_w = 1;
			words++;
		}
		if (s[i] == c)
			in_w = 0;
		i++;
	}
	return (words);
}

static char	**ft_dup_word(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	start;
	int	end;
	int	words;

	i = 0;
	j = 0;
	words = ft_count_w(s, c);
	while (i < words)
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j])
			j++;
		end = j;
		arr[i] = ft_get_w(s, start, end);
		if (!arr[i])
			return (ft_free(arr, i));
		i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((ft_count_w(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (ft_dup_word(arr, s, c));
}
