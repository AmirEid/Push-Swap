/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:50:52 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 18:16:26 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

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

bool	sa_checker(t_node **a, int flag)
{
	ft_swapper(a);
	if (!flag)
		ft_printf("sa\n");
	return (true);
}

bool	sb_checker(t_node **b, int flag)
{
	if (*b)
	{
		ft_swapper(b);
		if (!flag)
			ft_printf("sb\n");
		return (true);
	}
	return (false);
}

bool	ss_checker(t_node **a, t_node **b, int flag)
{
	if (*b)
	{
		ft_swapper(a);
		ft_swapper(b);
		if (!flag)
			ft_printf("ss\n");
		return (true);
	}
	return (false);
}
