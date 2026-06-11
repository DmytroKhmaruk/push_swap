/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 08:08:22 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 08:16:21 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (first->next)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **a, t_stats *stats)
{
	swap(a);
	stats->sa++;
	print_op("sa\n", stats);
}

void	sb(t_stack **b, t_stats *stats)
{
	swap(b);
	stats->sb++;
	print_op("sb\n", stats);
}

void	ss(t_stack **a, t_stack **b, t_stats *stats)
{
	swap(a);
	swap(b);
	stats->ss++;
	print_op("ss\n", stats);
}
