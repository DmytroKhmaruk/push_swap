/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 08:54:48 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 12:54:54 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_min_to_top(t_stack **a, int index, int size, t_stats *stats)
{
	int	pos;

	pos = get_position(*a, index);
	if (pos <= size / 2)
	{
		while ((*a)->index != index)
			ra(a, stats);
	}
	else
	{
		while ((*a)->index != index)
			rra(a, stats);
	}
}

void	insertion_sort(t_stack **a, t_stack **b, int size, t_stats *stats)
{
	int	index;

	index = 0;
	if (size <= 5)
		return (small_sort(a, b, size, stats));
	while (size > 3)
	{
		move_min_to_top(a, index, size, stats);
		pb(a, b, stats);
		index++;
		size--;
	}
	sort_three(a, stats);
	while (*b)
		pa(b, a, stats);
}
