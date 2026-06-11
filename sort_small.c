/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:06:12 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 12:54:01 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_stats *stats)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first < second && second < third)
		return ;
	if (first > second && second > third)
		return (sa(a, stats), rra(a, stats));
	if (first < second && first < third && second > third)
		return (rra(a, stats), sa(a, stats));
	if (first < second && first > third && second > third)
		return (rra(a, stats));
	if (first > second && first > third && second < third)
		return (ra(a, stats));
	if (first > second && first < third && second < third)
		return (sa(a, stats));
}

static void	move_index_to_top(t_stack **a, int index, int size, t_stats *stats)
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

void	small_sort(t_stack **a, t_stack **b, int size, t_stats *stats)
{
	if (size == 2 && (*a)->index > (*a)->next->index)
		return (sa(a, stats));
	if (size == 3)
		return (sort_three(a, stats));
	move_index_to_top(a, 0, size, stats);
	pb(a, b, stats);
	if (size == 5)
	{
		move_index_to_top(a, 1, size - 1, stats);
		pb(a, b, stats);
	}
	sort_three(a, stats);
	if (size == 5)
		pa(b, a, stats);
	pa(b, a, stats);
}
