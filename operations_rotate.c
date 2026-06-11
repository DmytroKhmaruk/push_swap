/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 07:58:11 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 08:00:14 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = stack_last(*stack);
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, t_stats *stats)
{
	rotate(a);
	stats->ra++;
	print_op("ra\n", stats);
}

void	rb(t_stack **b, t_stats *stats)
{
	rotate(b);
	stats->rb++;
	print_op("rb\n", stats);
}

void	rr(t_stack **a, t_stack **b, t_stats *stats)
{
	rotate(a);
	rotate(b);
	stats->rr++;
	print_op("rr\n", stats);
}
