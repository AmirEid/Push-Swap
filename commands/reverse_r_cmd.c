/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:14:39 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 18:11:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last_t_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_t_node = get_last_t_node(*stack);
	last_t_node->next = *stack;
	last_t_node->prev->next = NULL;
	(*stack)->prev = last_t_node;
	last_t_node = last_t_node->prev;
	(*stack)->prev->prev = NULL;
	*stack = (*stack)->prev;
}

bool	rra_checker(t_node **a, int flag)
{
	reverse_rotate(a);
	if (!flag)
		ft_printf("rra\n");
	return (true);
}

bool	rrb_checker(t_node **b, int flag)
{
	if (*b)
	{
		reverse_rotate(b);
		if (!flag)
			ft_printf("rrb\n");
		return (true);
	}
	return (false);
}

bool	rrr_checker(t_node **a, t_node **b, int flag)
{
	if (*b)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		if (!flag)
			ft_printf("rrr\n");
		return (true);
	}
	return (false);
}
