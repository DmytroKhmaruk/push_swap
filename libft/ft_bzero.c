/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:38:49 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 11:41:34 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
int main(void)
{
	char	str[] = "Hello Universe";
	int		i;

	ft_bzero(str, 6);
	i = 0;
	while (i < 15)
	{
		printf("%02x ", (unsigned char)str[i]);
		i++;
	}
	printf("\n");

	return (0);
}
*/
