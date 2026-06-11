/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:29:17 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 14:51:01 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>

int	main(void)
{

	printf("%d\n", ft_strncmp("abc", "abc", 3));
	printf("%d\n", ft_strncmp("abc", "acd", 3));
	printf("%d\n", ft_strncmp("abc", "abd", 2));
	printf("%d\n", ft_strncmp("abc", "ab", 3));
	printf("%d\n", ft_strncmp("abc", "xyz", 0));

	return (0);
}
*/
