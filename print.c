/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 08:33:38 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/08 16:41:12 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(char *op, t_stats *stats)
{
	ft_putstr_fd(op, 1);
	stats->total++;
}

static void	put_disorder(double disorder)
{
	int	percent;

	percent = (int)(disorder * 10000);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(percent / 100, 2);
	ft_putstr_fd(".", 2);
	if ((percent % 100) < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(percent % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	put_strategy(t_stats *stats)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (stats->strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple / O(n²)\n", 2);
	else if (stats->strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (stats->strategy == STRATEGY_COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else if (stats->disorder < 0.2)
		ft_putstr_fd("Adaptive / O(n²)\n", 2);
	else if (stats->disorder < 0.5)
		ft_putstr_fd("Adaptive / O(n√n)\n", 2);
	else
		ft_putstr_fd("Adaptive / O(n log n)\n", 2);
}

static void	put_op_counts(t_stats *stats)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(stats->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(stats->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(stats->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(stats->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(stats->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(stats->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(stats->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(stats->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(stats->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(stats->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(stats->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_stats *stats)
{
	put_disorder(stats->disorder);
	put_strategy(stats);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(stats->total, 2);
	ft_putstr_fd("\n", 2);
	put_op_counts(stats);
}
