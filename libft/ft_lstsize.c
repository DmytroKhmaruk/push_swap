/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 07:22:59 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 18:20:38 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
#include <stdio.h>
int main(void)
{
	t_list	*favorite;
	t_list	*current;

	favorite = NULL;
	char *str1 = "Blinding Lights";
	char *str2 = "Drop Dead";
	char *str3 = "I Just Might";
	char *str4 = "Hello";

	ft_lstadd_front(&favorite, ft_lstnew(str1));
	ft_lstadd_front(&favorite, ft_lstnew(str2));
	ft_lstadd_front(&favorite, ft_lstnew(str3));
	ft_lstadd_front(&favorite, ft_lstnew(str4));
	
	current = favorite;
	while (current)
	{
		printf("%s\n", (char *)current->content);	
		current = current->next;	
	}

	printf("size: %d\n",ft_lstsize(favorite));

	return (0);
}
*/
