/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 08:59:56 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 09:01:16 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_stack	*current;
	t_stack	*tmp;
	int		total_pairs;
	int		mistakes;

	current = a;
	total_pairs = 0;
	mistakes = 0;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			total_pairs++;
			if (current->value > tmp->value)
				mistakes++;
			tmp = tmp->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
