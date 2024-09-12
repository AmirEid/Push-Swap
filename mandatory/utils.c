/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:26:59 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 15:37:50 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_node	*get_last_t_node(t_node *first_t_node)
{
	if (!first_t_node)
		return (NULL);
	while (first_t_node->next != NULL)
		first_t_node = first_t_node->next;
	return (first_t_node);
}

void	free_matrix(char **argv)
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

int	create_t_node(t_node **stack, int val)
{
	t_node	*head;
	t_node	*tail;

	if (!stack)
		return (0);
	head = malloc(sizeof(t_node));
	if (!head)
		return (0);
	head->next = NULL;
	head->value = val;
	head->cheapest = 0;
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
	return (1);
}

void	everyone_go_home(t_node **stack)
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

int	t_nodes_counter(t_node *first_t_node)
{
	int	i;

	if (!first_t_node)
		return (0);
	i = 0;
	while (first_t_node != NULL)
	{
		i++;
		first_t_node = first_t_node->next;
	}
	return (i);
}
