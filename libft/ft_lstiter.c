/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:13:13 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 18:45:53 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
/*
#include <stdio.h>

void	print_content(void *content)
{
	printf("Song: %s\n", (char *)content);
}

int	main(void)
{
	t_list	*list;

	list = ft_lstnew("Hello");
	if (!list)
		return (1);
	ft_lstiter(list, print_content);
	free(list);

	return (0);
}
*/
