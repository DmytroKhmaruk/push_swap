/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:43:44 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/01 16:40:33 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstadd_back(t_list **list, char *argv[])
{
	t_list	*tmp;
	t_list	*new_node;

	tmp = *list;
	tmp = ft_lstlast(tmp);
	while (*argv)
	{
		new_node = lstnew(ft_atoi(*argv), tmp);
		if (!new_node)
		{
			ft_clean_all(list);
			return (0);
		}	
		tmp->next = new_node;
		tmp = tmp->next;
		argv++;
	}
	return (1);
}
