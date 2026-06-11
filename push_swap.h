/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:14:54 by zorwa             #+#    #+#             */
/*   Updated: 2026/06/07 13:05:28 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_parsed
{
	int	*values;
	int	size;
}	t_parsed;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stats
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	int		bench;
	int		strategy;
	double	disorder;
}	t_stats;

# define STRATEGY_ADAPTIVE 0
# define STRATEGY_SIMPLE 1
# define STRATEGY_MEDIUM 2
# define STRATEGY_COMPLEX 3

int			write_error(void);
void		free_str_array(char **array);
void		free_parsed(t_parsed *parsed);

char		**split_by_whitespace(const char *s);
int			is_valid_input(int argc, char **argv, int start);
t_parsed	parse_arguments(int argc, char **argv, int start);
int			parse_options(int argc, char **argv, t_stats *stats);
void		init_stats(t_stats *stats);

t_stack		*stack_new(int value);
int			stack_add_back(t_stack **stack, int value);
void		stack_clear(t_stack **stack);
t_stack		*stack_last(t_stack *stack);
int			stack_size(t_stack *stack);
int			get_position(t_stack *stack, int index);
int			stack_is_sorted(t_stack *stack);
t_stack		*build_stack(t_parsed parsed);

void		set_index(t_stack *a);
double		compute_disorder(t_stack *a);

void		print_op(char *op, t_stats *stats);
void		print_bench(t_stats *stats);

void		sa(t_stack **a, t_stats *stats);
void		sb(t_stack **b, t_stats *stats);
void		ss(t_stack **a, t_stack **b, t_stats *stats);
void		pa(t_stack **b, t_stack **a, t_stats *stats);
void		pb(t_stack **a, t_stack **b, t_stats *stats);
void		ra(t_stack **a, t_stats *stats);
void		rb(t_stack **b, t_stats *stats);
void		rr(t_stack **a, t_stack **b, t_stats *stats);
void		rra(t_stack **a, t_stats *stats);
void		rrb(t_stack **b, t_stats *stats);
void		rrr(t_stack **a, t_stack **b, t_stats *stats);

void		sort_three(t_stack **a, t_stats *stats);
void		small_sort(t_stack **a, t_stack **b, int size, t_stats *stats);
void		insertion_sort(t_stack **a, t_stack **b, int size, t_stats *stats);
void		medium_sort(t_stack **a, t_stack **b, int size, t_stats *stats);
void		radix_sort(t_stack **a, t_stack **b, int size, t_stats *stats);

#endif
