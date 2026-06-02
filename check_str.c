/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:44:37 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/01 17:26:34 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_str(char *argv[])
{
	int	i;
	int	x;

	i = 0;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x] == ' ' || (argv[i][x] >= 9 && argv[i][x] <= 13))
			x++;
		if (argv[i][x] == '-' || argv[i][x] == '+')
			x++;
		if (!argv[i][x])
			return (0);
		while (argv[i][x] >= '0' && argv[i][x] <= '9')
			x++;
		if (argv[i][x] && !(argv[i][x] >= '0' && argv[i][x] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
