/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:22:45 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 08:18:57 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!from || !*from)
		return ;
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	node->prev = NULL;
	if (*to)
		(*to)->prev = node;
	*to = node;
}

void	pa(t_stack **b, t_stack **a, t_stats *stats)
{
	push(b, a);
	stats->pa++;
	print_op("pa\n", stats);
}

void	pb(t_stack **a, t_stack **b, t_stats *stats)
{
	push(a, b);
	stats->pb++;
	print_op("pb\n", stats);
}
