/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:11:50 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 12:50:24 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static bool	execute_commands(t_node **a, t_node **b, char *line)
{
	if (ft_strncmp_checker(line, "sa\n", 3) == 0)
		return (sa_checker(a, 1));
	else if (ft_strncmp_checker(line, "pb\n", 3) == 0)
		return (pb_checker(a, b, 1));
	else if (ft_strncmp_checker(line, "ra\n", 3) == 0)
		return (ra_checker(a, 1));
	else if (ft_strncmp_checker(line, "rra\n", 4) == 0)
		return (rra_checker(a, 1));
	else if (ft_strncmp_checker(line, "sb\n", 3) == 0)
		return (sb_checker(b, 1));
	else if (ft_strncmp_checker(line, "ss\n", 3) == 0)
		return (ss_checker(a, b, 1));
	else if (ft_strncmp_checker(line, "pa\n", 3) == 0)
		return (pa_checker(a, b, 1));
	else if (ft_strncmp_checker(line, "rb\n", 3) == 0)
		return (rb_checker(b, 1));
	else if (ft_strncmp_checker(line, "rr\n", 3) == 0)
		return (rr_checker(a, b, 1));
	else if (ft_strncmp_checker(line, "rrr\n", 4) == 0)
		return (rrr_checker(a, b, 1));
	else if (ft_strncmp_checker(line, "rrb\n", 4) == 0)
		return (rrb_checker(b, 1));
	return (false);
}

static void	checker(t_node **a, t_node **b)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		free(line);
	while (line != NULL)
	{
		execute_commands(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	get_next_line(-42);
	if (*b || check_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		argv = ft_split_checker(argv[1], ' ');
	if (!argv)
		return (0);
	check_for_input_errors_initialize(&a, argv + 1, argc);
	checker(&a, &b);
	if (argc == 2)
		free_matrix_checker(argv);
	everyone_go_home_checker(&a);
	everyone_go_home_checker(&b);
	return (0);
}
