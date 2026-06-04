/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:16:04 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/04 15:52:39 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_stats *stats, char *disorder_alg)
{
	ft_printf_fd(2,"[bench] disorder:  %f%\n", stats->disorder *= 100);
	if (stats->adaptive_alg == 1)
		ft_printf_fd(2,"[bench] strategy:  %s / %s\n", "Adaptive", disorder_alg);
	else if (stats->simple_alg == 1)
		ft_printf_fd(2,"[bench] strategy:  %s / %s\n", "Simple", "O(n2)");
	else if (stats->medium_alg == 1)
		ft_printf_fd(2,"[bench] strategy:  %s / %s\n", "Medium", "O(n√n)");
	else if (stats->complex_alg == 1)
		ft_printf_fd(2,"[bench] strategy:  %s / %s\n", "Complex", "O(n log n)");
	ft_printf_fd(2,"[bench] total_ops: %d\n", stats->total);
	ft_printf_fd(2,"[bench] sa:  %d  sb:  %d  ss:  %d  pa:  %d  pb:  %d\n",
		stats->sa, stats->sb, stats->ss, stats->pa, stats->pb);
	ft_printf_fd(2,"[bench] ra:  %d  rb:  %d  rr:  %d  rra: %d  rrb: %d  rrr: %d\n",
 		stats->ra, stats->rb, stats->rr, stats->rra, stats->rrb, stats->rrr);
}
