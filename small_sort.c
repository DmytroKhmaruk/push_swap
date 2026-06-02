/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:06:14 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/02 13:24:27 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a, t_stats *stats)
{
	int		first;
	int		second;
	int		third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first < second && second < third)
		return ;
	else if (first > second && second > third)
	{
		sa(a, stats);
		rra(a, stats);
	}
	else if (first < second && first < third && second > third)
	{
		rra(a, stats);
		sa(a, stats);
	}
	else if (first < second && first > third && second > third)
		rra(a, stats);
	else if (first > second && first > third && second < third)
		ra(a, stats);
	else if (first > second && first < third && second < third)
		sa(a, stats);
}

void	move_index_to_top(t_list **a, t_list **b, int i, t_stats *stats)
{
	if ((*a)->next->index == i)
		sa(a, stats);
	else if ((*a)->next->next->index == i)
	{
		ra(a, stats);
		sa(a, stats);
	}
	while ((*a)->index != i)
		rra(a, stats);
	pb(a, b, stats);
}

void	small_sort(t_list **a, t_list **b, int size, t_stats *stats)
{
	move_index_to_top(a, b, 0, stats);
	if (size > 4)
		move_index_to_top(a, b, 1, stats);
	sort_three(a, stats);
	pa(b, a, stats);
	if (size > 4)
		pa(b, a, stats);
}

void	set_index(t_list **a)
{
	t_list	*tmp;
	t_list	*current;

	current = *a;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->value > tmp->value)
				current->index += 1;
			else
				tmp->index += 1;
			tmp = tmp->next;
		}
		current = current->next;
	}
}
