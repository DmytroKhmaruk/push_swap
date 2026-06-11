/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 10:26:50 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 17:20:33 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
char	incre_char(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

#include <stdio.h>
int	main(void)
{
	char	*result;

	result = ft_strmapi("abcd", incre_char);
	if (!result)
		return (1);
	printf("Result: %s\n", result);
	free(result);
	return (0);
}
*/
