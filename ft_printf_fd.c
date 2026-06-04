/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:29:51 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/04 12:32:24 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	print_char(int fd, int c, int *count)
{
	if (write(fd, &c, 1) < 0)
		return (-1);
	return (++(*count));
}


int	print_str(int fd, char *str, int *count)
{
	if (!str)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (*count += 6);
	}
	while (*str)
	{
		if (print_char(fd, (int)*str, count) == -1)
			return (-1);
		str++;
	}
	return (*count);
}



int	print_digit(int fd, unsigned long nbr, int base, char *hex, int *count)
{
	char	c;

	if (nbr >= (unsigned long)base)
		if (print_digit(fd, nbr / base, base, hex, count) == -1)
			return (-1);
	c = hex[nbr % base];
	if (print_char(fd, c, count) == -1)
		return (-1);
	return (*count);
}

int	check_digit(int fd, long nbr, int base, int *count)
{
	if (nbr == 0)
	{
		if (print_char(fd, '0', count) == -1)
			return (-1);
		return (*count);
	}
	if (nbr < 0)
	{
		if (print_char(fd, '-', count) == -1)
			return (-1);
		nbr *= -1;
	}
	if (print_digit(fd, nbr, base, "0123456789", count) == -1)
		return (-1);
	return (*count);
}

int	print_double(int fd, double nbr, int *count)
{
	long	whole;
	double	frac;
	int		i;

	whole = (long)nbr;
	frac = nbr - whole;
	if (check_digit(fd, whole, 10, count) == -1)
		return (-1);
	if (print_char(fd, '.', count) == -1)
		return (-1);
	i = 0;
	while(i < 2)
	{
	frac *= 10;
	if (print_char(fd, (int)frac + '0', count) == -1)
		return (-1);
	frac -= (int)frac;
	i++;
	}
	return (*count);
}

int	print_fmt(int fd, char specifier, va_list ap, int *count)
{
	if (specifier == 'c')
		return (print_char(fd, va_arg(ap, int), count));
	if (specifier == 's')
		return (print_str(fd, va_arg(ap, char *), count));
	if (specifier == 'f')
		return (print_double(fd, (va_arg(ap, double)), count));
	if (specifier == 'd' || specifier == 'i')
		return (check_digit(fd, (long)(va_arg(ap, int)), 10, count));
	else
		return (print_char(fd, '%', count), print_char(fd, specifier, count));
}

int	ft_printf_fd(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		count;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			if (print_fmt(fd, *(++fmt), ap, &count) == -1)
				return (va_end(ap), -1);
		}
		else if (print_char(fd, *fmt, &count) == -1)
			return (va_end(ap), -1);
		fmt++;
	}
	va_end(ap);
	return (count);
}
