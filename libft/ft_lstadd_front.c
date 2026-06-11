/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 22:30:59 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 18:15:53 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*favorite;
	char	*str;

	favorite = NULL;
	str = "Blinding Lights";

	ft_lstadd_front(&favorite, ft_lstnew(str));
	if (!favorite)
		return (1);
	printf("%s\n", (char *)favorite->content);
	free(favorite);

	return (0);
}
*/
