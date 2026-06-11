/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 10:08:39 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 16:35:49 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*dst;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*copy;

	copy = ft_strdup("Hello");
	if (!copy)
		return (1);
	printf("%s\n", copy);
	free(copy);

	return (0);
}
*/
