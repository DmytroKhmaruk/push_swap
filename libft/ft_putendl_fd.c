/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:20:46 by zorwa             #+#    #+#             */
/*   Updated: 2026/05/03 17:34:27 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("endl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	ft_putendl_fd("Hello From", fd);	
	ft_putendl_fd("Other Side", fd);	
	ft_putendl_fd("", fd);	
	ft_putendl_fd(NULL, fd);	
	close(fd);	
	return (0);
}
*/
