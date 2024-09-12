/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:02:31 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 15:14:59 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_threesome(t_node **stack)
{
	t_node	*big_guy;

	big_guy = find_big_guy(*stack);
	if (*stack == big_guy)
		ra(stack, 0);
	else if ((*stack)->next == big_guy)
		rra(stack, 0);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		return (0);
	check_initialize(&a, argv + 1, argc);
	if (check_sorted(a))
	{
		if (t_nodes_counter(a) == 2)
			sa(&a, 0);
		else if (t_nodes_counter(a) == 3)
			sort_threesome(&a);
		else
			sort_gang_bang(&a, &b);
	}
	if (argc == 2)
		free_matrix(argv);
	everyone_go_home(&a);
	return (0);
}
/*
//tester//
t_node	*tmp;
int		i = 0;
i = t_nodes_counter(a);
ft_printf("Number of t_nodes: %d\n", i);
pb(&a, &b, 0);
pb(&a, &b, 0);
tmp = a;
while (tmp != NULL)
{
	ft_printf("%d\n", tmp->value);
	tmp = tmp->next;
}
i = t_nodes_counter(a);
ft_printf("Number of t_nodes: %d\n", i);
ft_printf("------\n");
tmp = b;
while (tmp != NULL)
{
	ft_printf("%d\n", tmp->value);
	tmp = tmp->next;
}
i = t_nodes_counter(b);
ft_printf("Number of t_nodes: %d\n", i);
if (argc == 2)
	free_matrix(argv);
delete_t_node(&a);
delete_t_node(&b);*/