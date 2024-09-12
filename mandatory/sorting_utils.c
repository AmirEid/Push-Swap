/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:13:06 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 15:47:48 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	set_target_t_node_to_b(t_node *a, t_node *b)
{
	t_node	*target_t_node;
	t_node	*curr_b;
	int		closest_small;

	while (a)
	{
		closest_small = INT_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (a->value > curr_b->value && curr_b->value > closest_small)
			{
				target_t_node = curr_b;
				closest_small = curr_b->value;
			}
			curr_b = curr_b->next;
		}
		if (closest_small == INT_MIN)
			a->target_t_node = find_big_guy(b);
		else
			a->target_t_node = target_t_node;
		a = a->next;
	}
}

void	indexing(t_node *stack)
{
	int	i;
	int	middle;

	middle = t_nodes_counter(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= middle)
			stack->above_mid = 1;
		else
			stack->above_mid = 0;
		stack = stack->next;
		i++;
	}
}

int	check_sorted(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}

t_node	*find_small_guy(t_node *stack)
{
	int		min_size;
	t_node	*smallest_guy;

	if (!stack)
		return (NULL);
	min_size = INT_MAX;
	while (stack != NULL)
	{
		if (min_size > stack->value)
		{
			min_size = stack->value;
			smallest_guy = stack;
		}
		stack = stack->next;
	}
	return (smallest_guy);
}

t_node	*find_big_guy(t_node *stack)
{
	int		max_size;
	t_node	*biggest_guy;

	if (!stack)
		return (NULL);
	max_size = INT_MIN;
	while (stack != NULL)
	{
		if (max_size < stack->value)
		{
			max_size = stack->value;
			biggest_guy = stack;
		}
		stack = stack->next;
	}
	return (biggest_guy);
}
