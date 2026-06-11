/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:06:15 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/06 19:06:38 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*build_stack(t_parsed parsed)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = 0;
	while (i < parsed.size)
	{
		if (!stack_add_back(&a, parsed.values[i]))
		{
			stack_clear(&a);
			return (NULL);
		}
		i++;
	}
	return (a);
}

void	set_index(t_stack *a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = a;
	while (current)
	{
		current->index = 0;
		current = current->next;
	}
	current = a;
	while (current)
	{
		tmp = a;
		while (tmp)
		{
			if (current->value > tmp->value)
				current->index++;
			tmp = tmp->next;
		}
		current = current->next;
	}
}
