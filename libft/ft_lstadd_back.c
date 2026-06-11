/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 10:52:40 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 18:27:15 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (!lst || !new)
		return ;
	end = ft_lstlast(*lst);
	if (!end)
	{
		*lst = new;
		return ;
	}
	end->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew("First"));
	ft_lstadd_back(&list, ft_lstnew("Second"));
	if (!list || !list->next)
		return (1);
	printf("%s\n",(char *)list->content);
	printf("%s\n",(char *)list->next->content);
	free(list->next);
	free(list);

	return (0);
}
*/
