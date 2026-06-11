/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 10:14:20 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/04 10:52:51 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
	*lst = NULL;
}
/*
static void	del(void *content)
{
	free(content);
}

#include <stdio.h>
int	main(void)
{
	t_list	*favorite;
	char	*content;

	favorite = NULL;
	content = ft_strdup("Blinding Lights");
	if (!content)
		return (1);
	favorite = ft_lstnew(content);
	if (!favorite)
	{
		free(content);
		return (1);
	}

	printf("Before clear size: %d\n", ft_lstsize(favorite));
	ft_lstclear(&favorite, del);
	
	if (favorite == NULL)
		printf("List cleared\n");

	return (0);
}
*/
