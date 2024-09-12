/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:11:35 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 15:21:30 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = NULL;
	cheapest = find_cheapest(*a);
	if (cheapest->above_mid && cheapest->target_t_node->above_mid)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_mid) && !(cheapest->target_t_node->above_mid))
		reverse_rotate_both(a, b, cheapest);
	check_if_both_on_top(a, cheapest, 'a');
	check_if_both_on_top(b, cheapest->target_t_node, 'b');
	pb(a, b, 0);
}

void	prepare_t_nodes_to_b(t_node *a, t_node *b)
{
	indexing(a);
	indexing(b);
	set_target_t_node_to_b(a, b);
	get_cost(a, b);
	set_cheapest(a);
}

void	prepare_t_nodes_to_a(t_node *a, t_node *b)
{
	indexing(a);
	indexing(b);
	set_target_t_node_to_a(a, b);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	check_if_both_on_top(a, (*b)->target_t_node, 'a');
	pa(a, b, 0);
}

void	sort_gang_bang(t_node **a, t_node **b)
{
	int	length;

	length = t_nodes_counter(*a);
	if (length-- > 3 && check_sorted(*a))
		pb(a, b, 0);
	if (length-- > 3 && check_sorted(*a))
		pb(a, b, 0);
	while (length-- > 3 && check_sorted(*a))
	{
		prepare_t_nodes_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	sort_threesome(a);
	while (*b)
	{
		prepare_t_nodes_to_a(*a, *b);
		move_b_to_a(a, b);
	}
	indexing(*a);
	check_min_on_top(a);
}
/* TESTER
void	sort_gang_bang(t_node **a, t_node **b)
{
	int	length;

	length = t_nodes_counter(*a);
	if (length-- > 3 && check_sorted(*a))
		pb(a, b, 0);
	if (length-- > 3 && check_sorted(*a))
		pb(a, b, 0);
	while (length-- > 3 && check_sorted(*a))
	{
		prepare_t_nodes_to_b(*a, *b);
		move_a_to_b(a, b);
	}
	t_node *tmp = *a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("------\n");
	tmp = *b;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	sort_threesome(a);
	tmp = *a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("------\n");
	tmp = *b;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	while (*b)
		{
			prepare_t_nodes_to_a(*a, *b);
			move_b_to_a(a, b);
		}
	tmp = *a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("------\n");
	tmp = *b;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	indexing(*a);
	check_min_on_top(a);
	tmp = *a;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("------\n");
	tmp = *b;
	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
}*/