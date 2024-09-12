/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:40:47 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 00:19:57 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	check_if_both_on_top(t_node **stack, t_node *cheapest_top, char flag)
{
	while (*stack != cheapest_top)
	{
		if (flag == 'a')
		{
			if (cheapest_top->above_mid)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (flag == 'b')
		{
			if (cheapest_top->above_mid)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	set_target_t_node_to_a(t_node *a, t_node *b)
{
	t_node	*target_t_node;
	t_node	*current_a;
	long	closest_big;

	while (b)
	{
		closest_big = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (b->value < current_a->value && current_a->value < closest_big)
			{
				closest_big = current_a->value;
				target_t_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_big == LONG_MAX)
			b->target_t_node = find_small_guy(a);
		else
			b->target_t_node = target_t_node;
		b = b->next;
	}
}

void	check_min_on_top(t_node **a)
{
	t_node	*smallest;

	smallest = find_small_guy(*a);
	while ((*a)->value != smallest->value)
	{
		if (smallest->above_mid)
			ra(a, 0);
		else
			rra(a, 0);
	}
}
