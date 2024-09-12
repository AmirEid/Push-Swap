/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:50:52 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 00:19:59 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_swapper(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next != NULL)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_node **a, int flag)
{
	ft_swapper(a);
	if (!flag)
		ft_printf("sa\n");
}

void	sb(t_node **b, int flag)
{
	ft_swapper(b);
	if (!flag)
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b, int flag)
{
	ft_swapper(a);
	ft_swapper(b);
	if (!flag)
		ft_printf("ss\n");
}
