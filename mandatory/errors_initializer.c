/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_initializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:55:02 by aeid              #+#    #+#             */
/*   Updated: 2024/03/28 15:08:20 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	syntax_errors(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i] == '-' || argv[i] == '+' || (argv[i] >= '0'
				&& argv[i] <= '9')))
		return (1);
	i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9' && argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static long	ft_atol(char *argv)
{
	long	result;
	int		parity;
	int		i;

	i = 0;
	parity = 1;
	result = 0;
	while (argv[i] == ' ' || (argv[i] >= 9 && argv[i] <= 13))
		i++;
	if (argv[i] == '-' || argv[i] == '+')
	{
		if (argv[i] == '-')
			parity *= -1;
		i++;
	}
	while (argv[i] >= '0' && argv[i] <= '9' && argv[i])
	{
		result = (result * 10) + (argv[i] - 48);
		i++;
	}
	return (result * parity);
}

static int	duplication_error(char **argv, char *curr_argv)
{
	int		i;
	long	number;
	long	next_number;

	number = ft_atol(curr_argv);
	i = 0;
	next_number = 0;
	while (argv[i])
	{
		next_number = ft_atol(argv[i]);
		if (next_number == number)
			return (1);
		i++;
	}
	return (0);
}

void	error_handler(t_node **a, char **argv, int argc)
{
	if (argc == 2)
		free_matrix(--argv);
	everyone_go_home(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_initialize(t_node **a, char **argv, int argc)
{
	int		i;
	long	value;
	int		flag;

	i = 0;
	while (argv[i])
	{
		flag = syntax_errors(argv[i]);
		if (flag)
			error_handler(a, argv, argc);
		flag = duplication_error(argv + i + 1, argv[i]);
		if (flag)
			error_handler(a, argv, argc);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN || !value)
			error_handler(a, argv, argc);
		flag = create_t_node(a, (int)value);
		if (!flag)
			error_handler(a, argv, argc);
		i++;
	}
}

/*TESTER
		ft_printf("this is len: %d\n", len);
		ft_printf("this is argv[i]: %s\n", curr_argv);
		ft_printf("this is curr_argv: %s\n", argv[i]);*/
/*
static int	duplication_error(char **argv, char *curr_argv)
{
	int	i;
	int	flag;
	int	len_curr;
	int	len_argv;
	int	len;

	i = 1;
	len_curr = ft_strlen(curr_argv);
	while (argv[i] != NULL)
	{
		len_argv = ft_strlen(argv[i]);
		if (len_argv > len_curr)
			len = len_argv;
		else
			len = len_curr;
		flag = ft_strncmp(curr_argv, argv[i], len);
		if (flag == 0)
			return (1);
		i++;
	}
	return (0);
}*/