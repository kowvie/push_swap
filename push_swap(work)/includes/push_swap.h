/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:22:18 by husobral          #+#    #+#             */
/*   Updated: 2026/07/30 12:26:29 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
}	t_ps;

typedef	enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

t_node	*new_node(int value);
void	stack_add_front(t_node **stack, t_node *new);
void	stack_add_back(t_node **stack, t_node *new);
int	stack_size(t_node *stack);
t_node	*last_node(t_node *stack);
int	find_min(t_node *stack);
int	find_max(t_node *stack);
int	is_sorted(t_node *stack);
void	free_stack(t_node **stack);
t_node	*find_min_node(t_node *stack);
t_node	*find_max_node(t_node *stack);
int	ft_strlen(char *str);
void	swap(t_node **stack);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	push(t_node **src, t_node **dest);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rotate(t_node **stack);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	print_op(char *op);
void    reverse_rotate(t_node **stack);
int is_valid_number(char *str);
long    ft_atol(const char *str);
int     is_int_range(char *str);
void    error_exit(void);
int	has_duplicate(t_node *stack, int value);
void	error_free(t_node **stack);
t_node	*parse_args(int argc, char **argv);
double  compute_disorder(t_node *a);
int is_strategy_flag(char *arg);
t_strategy get_strategy(char *arg);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
t_strategy  select_adaptive(double disorder);

void	print_stack_reverse(t_node *stack);
#endif