/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:02:43 by aeid              #+#    #+#             */
/*   Updated: 2024/02/29 00:22:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Printft/ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_node
{
	int				value;
	int				index;
	int				above_mid;
	int				cost;
	int				cheapest;
	struct t_node	*target_t_node;
	struct t_node	*next;
	struct t_node	*prev;

}					t_node;

//UTILS//
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				**ft_split(char const *str, char c);
t_node				*get_last_t_node(t_node *first_t_node);
void				free_matrix(char **argv);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
void				error_handler(t_node **a, char **argv, int argc);
int					t_nodes_counter(t_node *first_t_node);
void				check_initialize(t_node **a, char **argv, int argc);
int					create_t_node(t_node **stack, int val);
void				everyone_go_home(t_node **stack);
t_node				*find_small_guy(t_node *stack);
t_node				*find_big_guy(t_node *stack);
int					check_sorted(t_node *stack);
void				indexing(t_node *stack);
void				set_target_t_node_to_b(t_node *a, t_node *b);
void				get_cost(t_node *a, t_node *b);
void				set_cheapest(t_node *stack);
void				move_a_to_b(t_node **a, t_node **b);
t_node				*find_cheapest(t_node *stack);
void				rotate_both(t_node **a, t_node **b, t_node *cheapest);
void				reverse_rotate_both(t_node **a, t_node **b,
						t_node *cheapest);
void				check_if_both_on_top(t_node **stack, t_node *cheapest_top,
						char flag);
void				set_target_t_node_to_a(t_node *a, t_node *b);
void				check_min_on_top(t_node **a);

//CMDS//
void				sa(t_node **a, int flag);
void				sb(t_node **b, int flag);
void				ss(t_node **a, t_node **b, int flag);
void				ra(t_node **a, int flag);
void				rb(t_node **b, int flag);
void				rr(t_node **a, t_node **b, int flag);
void				rra(t_node **a, int flag);
void				rrb(t_node **b, int flag);
void				rrr(t_node **a, t_node **b, int flag);
void				pa(t_node **a, t_node **b, int flag);
void				pb(t_node **a, t_node **b, int flag);

//PUSH_SWAP//
void				sort_threesome(t_node **stack);
void				prepare_t_nodes_to_b(t_node *a, t_node *b);
void				sort_gang_bang(t_node **a, t_node **b);
void				prepare_t_nodes_to_a(t_node *a, t_node *b);

#endif