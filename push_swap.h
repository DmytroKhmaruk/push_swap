/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:39:59 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/03 18:10:48 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdarg.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	bench;
	int	simple_alg;
	int	medium_alg;
	int	complex_alg;
	int	adaptive_alg;
}			t_stats;

int		ft_printf_fd(int fd, const char *fmt, ...);
void	print_op(char *op, t_stats *stats);
void	print_bench(t_stats *stats);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_flag(int *argc, char ***argv, t_stats *stats);

void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *nptr);
void	ft_clean_all(t_list **list);
int		check_str(char *argv[]);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		ft_lstadd_back(t_list **list, char *argv[]);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*lstnew(int value, t_list *prev);

void	pa(t_list **b, t_list **a, t_stats *stats);
void	pb(t_list **a, t_list **b, t_stats *stats);
void	sa(t_list **a, t_stats *stats);
void	sb(t_list **b, t_stats *stats);
void	ss(t_list	**a, t_list	**b, t_stats *stats);
void	ra(t_list **a, t_stats *stats);
void	rb(t_list **b, t_stats *stats);
void	rr(t_list **a, t_list **b, t_stats *stats);
void	rra(t_list **a, t_stats *stats);
void	rrb(t_list **b, t_stats *stats);
void	rrr(t_list **a, t_list **b, t_stats *stats);

void	set_index(t_list **a);
void	sort_three(t_list **stack, t_stats *stats);
void	small_sort(t_list **a, t_list **b, int size, t_stats *stats);
void	insertion_sort(t_list **a, t_list **b, int size, t_stats *stats);
#endif
