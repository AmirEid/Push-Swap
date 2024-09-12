/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:29:45 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 18:12:36 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	push(t_node **src, t_node **dest)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!*dest)
	{
		*dest = tmp;
		(*dest)->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		(*dest)->prev = tmp;
		*dest = tmp;
	}
}

bool	pa_checker(t_node **a, t_node **b, int flag)
{
	if (*b)
	{
		push(b, a);
		if (!flag)
			ft_printf("pa\n");
		return (true);
	}
	return (false);
}

bool	pb_checker(t_node **a, t_node **b, int flag)
{
	push(a, b);
	if (!flag)
		ft_printf("pb\n");
	return (true);
}
