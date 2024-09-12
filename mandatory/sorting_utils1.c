/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:06:53 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 15:40:19 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_t_node)
		rr(a, b, 0);
	indexing(*a);
	indexing(*b);
}

void	reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target_t_node)
		rrr(a, b, 0);
	indexing(*a);
	indexing(*b);
}

t_node	*find_cheapest(t_node *stack)
{
	t_node	*cheapest;

	cheapest = NULL;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
		{
			cheapest = stack;
			return (cheapest);
		}
		else
			stack = stack->next;
	}
	return (NULL);
}

void	get_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

	len_a = t_nodes_counter(a);
	len_b = t_nodes_counter(b);
	while (a)
	{
		a->cost = a->index;
		if (a->above_mid == 0)
			a->cost = len_a - (a->index);
		if (a->target_t_node->above_mid)
			a->cost += a->target_t_node->index;
		else
			a->cost += len_b - (a->target_t_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_node *stack)
{
	t_node	*cheapest_t_node;
	int		min_val;

	if (!stack)
		return ;
	min_val = INT_MAX;
	cheapest_t_node = stack;
	while (stack)
	{
		if (stack->cost < min_val)
		{
			min_val = stack->cost;
			cheapest_t_node = stack;
		}
		stack = stack->next;
	}
	cheapest_t_node->cheapest = 1;
}
