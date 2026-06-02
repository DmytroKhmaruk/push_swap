/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:38:08 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/02 13:48:58 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_position(t_list *a, int	index)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index == index)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	insertion_sort(t_list **a, t_list **b, int size, t_stats *stats)
{
	int		index;
	int		pos;

	index = 0;
	if (size > 3)
	{
		while (size > 3)
		{
			pos = get_position(*a, index);
			if (pos == -1)
				return ;
			if (pos <= (size / 2))
				while ((*a)->index != index)
						ra(a, stats);
			else
				while ((*a)->index != index)
					rra(a, stats);
			pb(a,b, stats);
			index++;
			size--;
		}
		sort_three(a, stats);
	while (index--)
	pa(b,a, stats);
	}
	else if (size == 3)
 		sort_three(a, stats);
	else if (size == 2)
		sa(a, stats);
}
