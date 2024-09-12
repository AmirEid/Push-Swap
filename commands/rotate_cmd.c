/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:16:22 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 18:15:08 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	rotation(t_node **stack)
{
	t_node	*last_t_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_t_node = get_last_t_node(*stack);
	(*stack)->prev = last_t_node;
	(*stack)->next->prev = NULL;
	last_t_node->next = *stack;
	last_t_node = *stack;
	*stack = (*stack)->next;
	last_t_node->next = NULL;
}

bool	ra_checker(t_node **a, int flag)
{
	rotation(a);
	if (!flag)
		ft_printf("ra\n");
	return (true);
}

bool	rb_checker(t_node **b, int flag)
{
	if (*b)
	{
		rotation(b);
		if (!flag)
			ft_printf("rb\n");
		return (true);
	}
	return (false);
}

bool	rr_checker(t_node **a, t_node **b, int flag)
{
	if (*b)
	{
		rotation(a);
		rotation(b);
		if (!flag)
			ft_printf("rr\n");
		return (true);
	}
	return (false);
}
