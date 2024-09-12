/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:16:22 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 00:19:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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

void	ra(t_node **a, int flag)
{
	rotation(a);
	if (!flag)
		ft_printf("ra\n");
}

void	rb(t_node **b, int flag)
{
	rotation(b);
	if (!flag)
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b, int flag)
{
	rotation(a);
	rotation(b);
	if (!flag)
		ft_printf("rr\n");
}
