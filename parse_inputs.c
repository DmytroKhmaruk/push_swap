/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 18:17:19 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/06 19:01:07 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_total_tokens(int argc, char **argv, int start)
{
	char	**tokens;
	int		total;
	int		j;

	total = 0;
	while (start < argc)
	{
		tokens = split_by_whitespace(argv[start]);
		if (!tokens)
			return (-1);
		j = 0;
		while (tokens[j])
			j++;
		total += j;
		free_str_array(tokens);
		start++;
	}
	return (total);
}

static int	fill_values(int argc, char **argv, int start, int *values)
{
	char	**tokens;
	int		i;
	int		j;

	i = 0;
	while (start < argc)
	{
		tokens = split_by_whitespace(argv[start]);
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j])
		{
			values[i] = ft_atoi(tokens[j]);
			i++;
			j++;
		}
		free_str_array(tokens);
		start++;
	}
	return (1);
}

static int	has_duplicates(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_parsed	parse_arguments(int argc, char **argv, int start)
{
	t_parsed	result;

	result.values = NULL;
	result.size = count_total_tokens(argc, argv, start);
	if (result.size <= 0)
		return (result);
	result.values = malloc(sizeof(int) * result.size);
	if (!result.values)
	{
		result.size = 0;
		return (result);
	}
	if (!fill_values(argc, argv, start, result.values))
	{
		free_parsed(&result);
		return (result);
	}
	if (has_duplicates(result.values, result.size))
	{
		free_parsed(&result);
		return (result);
	}
	return (result);
}
