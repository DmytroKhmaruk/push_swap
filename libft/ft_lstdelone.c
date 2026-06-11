/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 09:45:07 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 18:31:32 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node;
	char	*content;

	content = ft_strdup("Hello");
	if (!content)
		return (1);
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (1);
	}
	ft_lstdelone(node, free);

	return (0);
}
*/
