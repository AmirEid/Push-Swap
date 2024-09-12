/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:12:16 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 19:04:54 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../Printft/ft_printf.h"
# include "../headers/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				value;
	struct t_node	*next;
	struct t_node	*prev;
}					t_node;

char				*ft_substr_checker(const char *s, unsigned int start,
						size_t len);
char				**ft_split_checker(char const *str, char c);
void				check_for_input_errors_initialize(t_node **a, char **argv,
						int argc);
void				free_matrix_checker(char **argv);
void				everyone_go_home_checker(t_node **stack);
size_t				ft_strlen_checker(const char *str);
int					ft_strncmp_checker(const char *s1, const char *s2,
						size_t n);
void				error_handler_checker(t_node **a, char **argv, int argc);
bool				create_t_node_checker(t_node **stack, int val);
char				*ft_strchr_checker(char *str, int c);
t_node				*get_last_t_node(t_node *first_t_node);
int					check_sorted(t_node *stack);

//commands//
bool				pa_checker(t_node **a, t_node **b, int flag);
bool				pb_checker(t_node **a, t_node **b, int flag);
bool				rra_checker(t_node **a, int flag);
bool				rrb_checker(t_node **b, int flag);
bool				rrr_checker(t_node **a, t_node **b, int flag);
bool				ra_checker(t_node **a, int flag);
bool				rb_checker(t_node **b, int flag);
bool				rr_checker(t_node **a, t_node **b, int flag);
bool				sa_checker(t_node **a, int flag);
bool				sb_checker(t_node **b, int flag);
bool				ss_checker(t_node **a, t_node **b, int flag);

#endif