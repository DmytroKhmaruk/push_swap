/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 03:05:14 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 16:13:10 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{

	printf("%d | %d\n", ft_atoi("42"), atoi("42"));
	printf("%d | %d\n", ft_atoi("--123"), atoi("--123"));
	printf("%d | %d\n", ft_atoi("+-123"), atoi("+-123"));
	printf("%d | %d\n", ft_atoi("   -42"), atoi("  -42"));
	printf("%d | %d\n", ft_atoi("+123abc"), atoi("+123abc"));

	return (0);
}
*/
