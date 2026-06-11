/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:58:34 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 18:11:10 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list *node;
	char	*str = "Milky Way Galaxy";

	node = ft_lstnew(str);
	if (!node)
		return (1);

	printf("content: %s\n", (char *)node->content);
	printf("Next: %p\n", node->next);
	free(node);

	return (0);
}
*/
