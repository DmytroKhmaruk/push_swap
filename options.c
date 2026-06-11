/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 08:58:44 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 08:58:57 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stats(t_stats *stats)
{
	ft_bzero(stats, sizeof(t_stats));
	stats->strategy = STRATEGY_ADAPTIVE;
}

static int	is_flag(char *arg, char *flag)
{
	return (ft_strncmp(arg, flag, ft_strlen(flag) + 1) == 0);
}

static int	set_strategy(char *arg, t_stats *stats)
{
	if (is_flag(arg, "--simple"))
		stats->strategy = STRATEGY_SIMPLE;
	else if (is_flag(arg, "--medium"))
		stats->strategy = STRATEGY_MEDIUM;
	else if (is_flag(arg, "--complex"))
		stats->strategy = STRATEGY_COMPLEX;
	else if (is_flag(arg, "--adaptive"))
		stats->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_options(int argc, char **argv, t_stats *stats)
{
	int	start;
	int	strategy_seen;
	int	is_strategy;

	start = 1;
	strategy_seen = 0;
	while (start < argc)
	{
		if (is_flag(argv[start], "--bench"))
			stats->bench = 1;
		else
		{
			is_strategy = set_strategy(argv[start], stats);
			if (is_strategy && !strategy_seen)
				strategy_seen = 1;
			else if (is_strategy && strategy_seen)
				return (-1);
			else
				break ;
		}
		start++;
	}
	return (start);
}
