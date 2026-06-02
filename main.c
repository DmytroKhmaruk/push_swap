/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhmaruk <dkhmaruk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 11:44:22 by dkhmaruk          #+#    #+#             */
/*   Updated: 2026/06/02 18:19:56 by dkhmaruk         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*tmp;
	char	**split;
	int		i;
	int		size;
	t_stats	stats;

	a = NULL;
	b = NULL;
	tmp = a;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	if (!ft_strncmp(argv[1], "--bench", 8))
	{
		stats.bench = 1;
		argv++;
		argc--;
	}
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
//	if (!a){
//		printf("NULL\n"); 
//		return (0);
//	}
	ft_bzero(&stats, sizeof(t_stats));
	tmp = a;
	printf("//////////////////\n");
	while (tmp)
	{
		printf("stack a befor push: %d\n", tmp->value);
		printf("index befor sort: %d\n\n", tmp->index);	
		tmp = tmp->next;
	}
	printf("//////////////////\n");
	size = ft_lstsize(a);
	set_index(&a);
	insertion_sort(&a, &b, size, &stats);
	printf("t_oper : %d\n", stats.total);
	printf("//////////////////\n");
	tmp = a;
	while (tmp)
	{
		printf("stack a: %d\n", tmp->value);
		printf("index after sort: %d\n\n", tmp->index);	
		tmp = tmp->next;
	}
	printf("//////////////////\n");
	tmp = b;
	while (tmp)
	{
		printf("stack b: %d\n", tmp->value);
		printf("index after sort: %d\n\n", tmp->index);	
		tmp = tmp->next;
	}
	printf("//////////////////\n");

	ft_clean_all(&a);
	ft_clean_all(&b);
	if (!a && !b)
		printf("after final free: NULL\n");
	return (0);
}
