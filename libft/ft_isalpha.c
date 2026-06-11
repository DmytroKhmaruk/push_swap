/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:40:34 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 09:21:44 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", ft_isalpha('z'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", ft_isalpha(' '));
	return (0);
}
*/
