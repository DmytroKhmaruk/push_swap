/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:13:16 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 13:07:47 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prepare_stack(int argc, char **argv, int start, t_stack **a)
{
	t_parsed	parsed;

	parsed = parse_arguments(argc, argv, start);
	if (!parsed.values)
		return (0);
	*a = build_stack(parsed);
	free_parsed(&parsed);
	if (!*a)
		return (0);
	return (1);
}

static void	run_sort(t_stack **a, t_stack **b, t_stats *stats)
{
	int	size;

	stats->disorder = compute_disorder(*a);
	set_index(*a);
	size = stack_size(*a);
	if (size <= 5)
		return (small_sort(a, b, size, stats));
	if (stats->strategy == STRATEGY_SIMPLE)
		insertion_sort(a, b, size, stats);
	else if (stats->strategy == STRATEGY_MEDIUM)
		medium_sort(a, b, size, stats);
	else if (stats->strategy == STRATEGY_COMPLEX)
		radix_sort(a, b, size, stats);
	else if (stats->disorder < 0.2)
		insertion_sort(a, b, size, stats);
	else if (stats->disorder < 0.5)
		medium_sort(a, b, size, stats);
	else
		radix_sort(a, b, size, stats);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stats	stats;
	int		start;

	a = NULL;
	b = NULL;
	init_stats(&stats);
	start = parse_options(argc, argv, &stats);
	if (start < 0)
		return (write_error());
	if (start >= argc)
		return (0);
	if (!is_valid_input(argc, argv, start))
		return (write_error());
	if (!prepare_stack(argc, argv, start, &a))
		return (write_error());
	if (!stack_is_sorted(a))
		run_sort(&a, &b, &stats);
	if (stats.bench)
		print_bench(&stats);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
