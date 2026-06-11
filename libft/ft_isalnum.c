/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:38:07 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 09:28:17 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalnum('0'));
	printf("%d\n", ft_isalnum('1'));
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", ft_isalnum('z'));
	printf("%d\n", ft_isalnum('@'));
	printf("%d\n", ft_isalnum('%'));
	return (0);
}
*/
