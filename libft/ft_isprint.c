/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:54:53 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 10:38:52 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isprint(9));
	printf("%d\n", ft_isprint('Z'));
	printf("%d\n", ft_isprint('\0'));
	printf("%d\n", ft_isprint(127));
	printf("%d\n", ft_isprint('a'));
	return (0);
}
*/
