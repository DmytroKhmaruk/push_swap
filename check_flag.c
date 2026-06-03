/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:25:09 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/03 18:24:23 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flag(int *argc, char ***argv, t_stats *stats)
{
	if (*argc > 1 && !ft_strncmp((*argv)[1], "--bench", 8))
	{
		stats->bench = 1;
		(*argv)++;
		(*argc)--;
	}
	if (*argc > 1 && !ft_strncmp((*argv)[1], "--simple", 8))
	{
		stats->simple_alg = 1;
		(*argv)++;
		(*argc)--;
	}
	else if (*argc > 1 && !ft_strncmp((*argv)[1], "--medium", 8))
	{
		stats->medium_alg = 1;
		(*argv)++;
		(*argc)--;
	}
	else if (*argc > 1 && !ft_strncmp((*argv)[1], "--complex", 9))
	{
		stats->complex_alg = 1;	
		(*argv)++;
		(*argc)--;
	}
	else if (*argc > 1 && !ft_strncmp((*argv)[1], "--adaptive", 10))
	{
		stats->adaptive_alg = 1;	
		(*argv)++;
		(*argc)--;
	}
	else
		stats->adaptive_alg = 1;
	if (*argc > 1 && !ft_strncmp((*argv)[1], "--bench", 8))
	{
		stats->bench = 1;
		(*argv)++;
		(*argc)--;
	}
}
