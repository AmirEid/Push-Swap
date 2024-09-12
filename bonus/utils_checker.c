/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:05:58 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 15:39:36 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	free_matrix_checker(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	everyone_go_home_checker(t_node **stack)
{
	t_node	*temp;
	t_node	*next_t_node;

	if (!stack || !(*stack))
		return ;
	temp = *stack;
	while (temp)
	{
		next_t_node = temp->next;
		temp->value = 0;
		free(temp);
		temp = next_t_node;
	}
	*stack = NULL;
}

bool	create_t_node_checker(t_node **stack, int val)
{
	t_node	*head;
	t_node	*tail;

	if (!stack)
		return (true);
	head = malloc(sizeof(t_node));
	if (!head)
		return (true);
	head->next = NULL;
	head->value = val;
	if (!(*stack))
	{
		*stack = head;
		head->prev = NULL;
	}
	else
	{
		tail = get_last_t_node(*stack);
		tail->next = head;
		head->prev = tail;
	}
	return (false);
}

t_node	*get_last_t_node(t_node *first_t_node)
{
	if (!first_t_node)
		return (NULL);
	while (first_t_node->next != NULL)
		first_t_node = first_t_node->next;
	return (first_t_node);
}

int	check_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}
