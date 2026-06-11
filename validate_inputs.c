/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:55:34 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/06 17:55:58 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_token(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

static long long	ft_atoll(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

static int	is_valid_int_range(const char *str)
{
	long long	num;

	if (!str)
		return (0);
	num = ft_atoll(str);
	if (num > 2147483647 || num < -2147483648)
		return (0);
	return (1);
}

static int	validate_argv_tokens(const char *argv)
{
	char	**tokens;
	int		i;

	if (!argv)
		return (0);
	tokens = split_by_whitespace(argv);
	if (!tokens)
		return (0);
	if (!tokens[0])
	{
		free_str_array(tokens);
		return (0);
	}
	i = 0;
	while (tokens[i])
	{
		if (!is_valid_token(tokens[i]) || !is_valid_int_range(tokens[i]))
		{
			free_str_array(tokens);
			return (0);
		}
		i++;
	}
	free_str_array(tokens);
	return (1);
}

int	is_valid_input(int argc, char **argv, int start)
{
	while (start < argc)
	{
		if (!validate_argv_tokens(argv[start]))
			return (0);
		start++;
	}
	return (1);
}
