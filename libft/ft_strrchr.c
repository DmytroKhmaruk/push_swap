/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:33:10 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 14:44:35 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		s_len;

	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if (s[s_len] == (unsigned char)c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	if (s[0] == (unsigned char)c)
		return ((char *)&s[0]);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello Level";	

	printf("%s\n", ft_strrchr(str, 'l'));
	printf("%s\n", ft_strrchr(str, 'h'));
	printf("%s\n", ft_strrchr(str, '\0'));
	printf("%s\n", ft_strrchr(str, 'H'));

	return (0);
}
*/
