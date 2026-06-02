/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:20:39 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/02 18:24:24 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	swap(t_list	**stack)
{
	t_list	*first;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	if ((*stack)->next)
		(*stack)->next->prev = first;
	first->prev = *stack;
	first->next = (*stack)->next;
	(*stack)->next = first;
}

void	sa(t_list **a, t_stats *stats)
{
	swap(a);
	stats->sa++;
	print_op("sa\n", stats);
}

void	sb(t_list **b, t_stats *stats)
{
	swap(b);
	stats->sb++;
	print_op("sb\n", stats);
}

void	ss(t_list **a, t_list **b, t_stats *stats)
{
	swap(a);
	swap(b);
	stats->ss++;
	print_op("ss\n", stats);
}

void	push(t_list **first_st, t_list **second_st)
{
	t_list	*tmp;

	if (!first_st || !*first_st)
		return ;
	tmp	= *first_st;
	*first_st = (*first_st)->next;
	if (*first_st)
		(*first_st)->prev = NULL;
	if (!*second_st)
	{
		*second_st = tmp;
		(*second_st)->next = NULL;
	}
	else
	{
		ft_lstadd_front(second_st, tmp);
		(*second_st)->next->prev = *second_st;
	}
}

void	pa(t_list **b, t_list **a, t_stats *stats)
{
	push(b, a);
	stats->pa++;
	print_op("pa\n", stats);
}

void	pb(t_list **a, t_list **b, t_stats *stats)
{
	push(a, b);
	stats->pb++;
	print_op("pb\n", stats);
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	first->prev = last;
}

void	ra(t_list **a, t_stats *stats)
{
		rotate(a);
		stats->ra++;
		print_op("ra\n", stats);
}

void	rb(t_list **b, t_stats *stats)
{
		rotate(b);
		stats->rb++;
		print_op("rb\n", stats);
}

void	rr(t_list **a, t_list **b, t_stats *stats)
{
		rotate(a);
		rotate(b);
		stats->rr++;
		print_op("rr\n", stats);
}

void	rev_rotate(t_list **stack)
{
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	last->next->prev = last;
	*stack = last;
}

void	rra(t_list **a, t_stats *stats)
{
		rev_rotate(a);
		stats->rra++;
		print_op("rra\n", stats);
}

void	rrb(t_list **b, t_stats *stats)
{
		rev_rotate(b);
		stats->rrb++;
		print_op("rrb\n", stats);
}

void	rrr(t_list **a, t_list **b, t_stats *stats)
{
		rev_rotate(a);
		rev_rotate(b);
		stats->rrr++;
		print_op("rrr\n", stats);
}
