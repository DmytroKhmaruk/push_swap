/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 08:07:03 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 08:07:08 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack **a, t_stats *stats)
{
	rev_rotate(a);
	stats->rra++;
	print_op("rra\n", stats);
}

void	rrb(t_stack **b, t_stats *stats)
{
	rev_rotate(b);
	stats->rrb++;
	print_op("rrb\n", stats);
}

void	rrr(t_stack **a, t_stack **b, t_stats *stats)
{
	rev_rotate(a);
	rev_rotate(b);
	stats->rrr++;
	print_op("rrr\n", stats);
}
