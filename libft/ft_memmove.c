/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:57:01 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 13:41:27 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
/*
#include <stdio.h>
int	main(void)
{
	char	buff[] = "ABCDEFGHIJ";

	//dest > src
	ft_memmove(buff + 2, buff, 5);
	printf("dest > src: %s\n", buff);

	//dest < src 
	char	biff[] = "ABCDEFGHIJ";
	ft_memmove(biff, biff + 2, 5);
	printf("dest < src: %s\n", biff);

	//dest == src
	char	eq[] = "ABCDEFGHIJ";
	ft_memmove(eq, eq, 5);
	printf("dest == src: %s\n", eq);

	return (0);
}
*/
