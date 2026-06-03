/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 17:33:51 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/03 17:20:19 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *op, t_stats *stats)
{
	if (!stats->bench)
		ft_printf_fd(1, "%s", op);
	stats->total++;	
}
