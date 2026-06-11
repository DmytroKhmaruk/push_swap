/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:10:33 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 11:09:37 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (s);
}
/*
#include <stdio.h>
int main(void)
{
	char	str[] = "Hello Universe";

	ft_memset(str, 42, 6);
	printf("%s\n", str);

	return (0);
}
*/
