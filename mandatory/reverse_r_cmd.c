/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:14:39 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 00:19:54 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	rra(t_node **a, int flag)
{
	reverse_rotate(a);
	if (!flag)
		ft_printf("rra\n");
}

void	rrb(t_node **b, int flag)
{
	reverse_rotate(b);
	if (!flag)
		ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b, int flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!flag)
		ft_printf("rrr\n");
}
