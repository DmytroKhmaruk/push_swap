/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:49:01 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/04 09:58:18 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_cont;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_cont = f(lst->content);
		new_node = ft_lstnew(new_cont);
		if (!new_node)
		{
			del(new_cont);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
#include <stdio.h>

static	void	del(void *content)
{
	free(content);
}

static void	*copy_content(void *content)
{
	return (ft_strdup((char *)content));	
}

int main(void)
{
	t_list	*old;
	t_list	*new;

	old = ft_lstnew("Hello");
	if (!old)
		return (1);
	new = ft_lstmap(old, copy_content, del);	
	if (!new)
	{
		free(old);
		return (1);
	}
	printf("%s\n", (char *)new->content);
	free(old);
	ft_lstclear(&new, del);

	return (0);
}
*/
