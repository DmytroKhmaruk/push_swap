/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 07:41:53 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 17:18:35 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long num)
{
	int	count;

	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

static void	fill_str(char *str, long num, size_t len, int is_neg)
{
	size_t	i;

	i = len;
	while (i > (size_t)is_neg)
	{
		i--;
		str[i] = (num % 10) + '0';
		num = num / 10;
	}
	if (is_neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*str;

	num = n;
	len = count_digit(num);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_str(str, num, len, n < 0);
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
	char	*str;

	str = ft_itoa(-2147483648);
	if (!str)
		return (1);
	printf("%s\n", str);
	free(str);

	return (0);
}
*/
