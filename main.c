/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:44:22 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/04 15:49:32 by dkhmaruk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_error()
{
	ft_printf_fd(2, "Error\n");
}

int	add_in_list(t_list **list, char	*argv[])
{
	if ((check_str(argv) == 0))
		return (0);
	if (!*list) {
		*list = lstnew(ft_atoi(*argv++), NULL);
			if (!*list)
				return (0);
		ft_lstadd_back(list, argv);
	}
	else 
		ft_lstadd_back(list, argv);
	return (1);
}

int	check_for_dup(t_list **list)
{
	t_list	*tmp;
	t_list	*current;

	current = *list;
	while (current)
	{
		tmp = current->next;
		while (tmp)
		{
			if (current->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		current = current->next;
	}
	return (1);
}

int	check_spaces(char	*argv[])
{
	int	i;
	int	x;

	i = 0;
	while (argv[i])
	{
		x = 0;
		while (argv[i][x] == ' ' || (argv[i][x] >= 9 && argv[i][x] <= 13))
			x++;
		if (!argv[i][x])
			return (0);
		i++;
	}
	return (1);
}

int	free_and_print_error(t_list **a)
{
	ft_clean_all(a);
	print_error();
	return (1);
}

double compute_disorder(t_list *a)
{
	t_list	*current;
	t_list	*tmp;
	int		total_pairs;
	int		mistakes;

	current = a;
	total_pairs = 0;
	mistakes = 0;
	while (current)
	{	
		tmp	= current->next;
		while(tmp)
		{
			total_pairs++;
			if (current->value > tmp->value)
				mistakes++;
			tmp = tmp->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	**split;
	int		i;
	int		size;
	t_stats	stats;

	a = NULL;
	b = NULL;
	ft_bzero(&stats, sizeof(t_stats));
	check_flag(&argc, &argv, &stats);
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (check_spaces(&argv[i]) == 0)
		{
			print_error();
			return (1);
		}
		split = ft_split(argv[i], ' ');
		if (add_in_list(&a, split) == 0)
			return (free_and_print_error(&a));
		free_split(split);
		i++;
	}
	if (check_for_dup(&a) == 0)
		return (free_and_print_error(&a));
	stats.disorder = compute_disorder(a);
	size = ft_lstsize(a);
	set_index(&a);
	if (stats.simple_alg == 1 || stats.disorder < 0.20)
		insertion_sort(&a, &b, size, &stats);
	else if (stats.medium_alg == 1 || stats.disorder < 0.50)
		insertion_sort(&a, &b, size, &stats);
	else if (stats.complex_alg == 1 || stats.disorder >= 0.50)
		insertion_sort(&a, &b, size, &stats);
	if (stats.bench == 1 && stats.disorder < 0.20)
		print_bench(&stats, "O(n2)");
	else if (stats.bench == 1 && stats.disorder < 0.50)
		print_bench(&stats, "O(n√n)");
	else if (stats.bench == 1 && stats.disorder >= 0.50)
		print_bench(&stats, "O(n log n)");
	ft_clean_all(&a);
	ft_clean_all(&b);
//	if (!a && !b)
//		printf("after final free: NULL\n");
	return (0);
}
