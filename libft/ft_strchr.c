/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:43:39 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 17:06:44 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
	char	str[] = "Hello";

	printf("%s\n", ft_strchr(str, 'e'));
	printf("%s\n", ft_strchr(str, 'o'));
	printf("%s\n", ft_strchr(str, 'x'));
	printf("%s\n", ft_strchr(str, '\0'));

	return (0);
}
*/
