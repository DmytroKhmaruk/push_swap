/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 09:13:26 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 18:21:39 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
int main(void)
{
	t_list *favorite;
	
	favorite = NULL;
	char *str1 = "Blinding Lights";
	char *str2 = "Drop Dead";
	char *str3 = "I Just Might";
	char *str4 = "Hello";

	ft_lstadd_front(&favorite, ft_lstnew(str1));
	ft_lstadd_front(&favorite, ft_lstnew(str2));
	ft_lstadd_front(&favorite, ft_lstnew(str3));
	ft_lstadd_front(&favorite, ft_lstnew(str4));
	
	printf("Last Node: %s\n", (char *)ft_lstlast(favorite)->content);
	
	return (0);
}
*/
