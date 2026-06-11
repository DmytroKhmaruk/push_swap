/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:03:32 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 13:04:32 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_index;
	int	bits;

	max_index = size - 1;
	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, int size, t_stats *stats)
{
	int	i;
	int	j;
	int	max_bits;

	i = 0;
	max_bits = get_max_bits(size);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, stats);
			else
				pb(a, b, stats);
			j++;
		}
		while (*b)
			pa(b, a, stats);
		i++;
	}
}
