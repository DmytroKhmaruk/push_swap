/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:34:25 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 09:23:52 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit('0'));
	printf("%d\n", ft_isdigit('z'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isdigit(' '));
	return (0);
}
*/
