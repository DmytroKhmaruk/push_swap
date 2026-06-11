/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:16:05 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 17:36:15 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd((int)(num / 10), fd);
	ft_putchar_fd((num % 10) + '0', fd);
}
/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("nbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) 
		return (1);

	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(12345, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(-42, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n', fd);

	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\n', fd);

	close(fd);
	return (0);
}
*/
