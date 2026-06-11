/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 11:13:22 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 12:55:28 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	while (chunk * chunk < size)
		chunk++;
	return (chunk);
}

static void	push_chunks_to_b(t_stack **a, t_stack **b, int size, t_stats *stats)
{
	int	chunk;
	int	limit;
	int	pushed;

	chunk = get_chunk_size(size);
	limit = chunk;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b, stats);
			pushed++;
			if (*b && (*b)->index < limit - (chunk / 2))
				rb(b, stats);
			if (pushed == limit && limit < size)
				limit += chunk;
			if (limit > size)
				limit = size;
		}
		else
			ra(a, stats);
	}
}

static void	move_index_to_top_b(t_stack **b, int index, t_stats *stats)
{
	int	pos;
	int	size;

	pos = get_position(*b, index);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while ((*b)->index != index)
			rb(b, stats);
	}
	else
	{
		while ((*b)->index != index)
			rrb(b, stats);
	}
}

void	medium_sort(t_stack **a, t_stack **b, int size, t_stats *stats)
{
	int	index;

	push_chunks_to_b(a, b, size, stats);
	index = size - 1;
	while (*b)
	{
		move_index_to_top_b(b, index, stats);
		pa(b, a, stats);
		index--;
	}
}
