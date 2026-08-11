/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:22:18 by husobral          #+#    #+#             */
/*   Updated: 2026/08/11 10:55:55 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdbool.h>

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

// jess 
typedef struct s_flags
{
	bool	simple;
	bool	medium;
	bool	complex;
	bool 	adaptive;
	bool	bench;
}	t_flags;

typedef enum e_countop
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_countop;

typedef struct s_bench
{
	int	active;
	long	counts[OP_COUNT];
	long	total;
	double	disorder;
	t_strategy requested;
	t_strategy executed;
}	t_bench;

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
void	sa(t_node **a, t_bench *bench);
void	sb(t_node **b, t_bench *bench);
void	ss(t_node **a, t_node **b, t_bench *bench);
void	push(t_node **src, t_node **dest);
void	pa(t_node **a, t_node **b, t_bench *bench);
void	pb(t_node **a, t_node **b, t_bench *bench);
void	rotate(t_node **stack);
void	ra(t_node **a, t_bench *bench);
void	rb(t_node **b, t_bench *bench);
void	rr(t_node **a, t_node **b, t_bench *bench);
void	print_op(char *op);
void    reverse_rotate(t_node **stack);
void    rra(t_node **a, t_bench *bench);
void    rrb(t_node **b, t_bench *bench);
void    rrr(t_node **a, t_node **b, t_bench *bench);
int is_valid_number(char *str);
long    ft_atol(const char *str);
int     is_int_range(char *str);
void    error_exit(void);
int	has_duplicate(t_node *stack, int value);
void	error_free(t_node **stack);
t_node	*parse_args(int argc, char **argv, int start);
double  compute_disorder(t_node *a);
int is_strategy_flag(char *arg);
t_strategy get_strategy(char *arg);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
t_strategy  select_adaptive(double disorder);
void    move_to_top(t_node **a, t_node *target, t_bench *bench);
void    move_to_top_b(t_node **b, t_node *target, t_bench *bench);
int get_position(t_node *stack, t_node *target);
void    simple_sort(t_node **a, t_node **b, t_bench *bench);
void    assign_indexes(t_node *stack);
t_node	*find_unindexed_min(t_node *stack);
int		int_sqrt(int n);
t_node	*find_max_index(t_node *stack);
void    medium_sort(t_node **a, t_node **b, t_bench *bench);

//jess
int 		check_split(char *str);
void    	free_split(char **numbers);
int 		check_string(char *str);
int 		check_flags(int argc, char **argv, t_flags *flags);
void		put_nbr(int fd, long n);
void    	put_str(int fd, const char *s);
	// bench
void    	print_op_count(t_bench *bench, int op, const char *name);
void    	print_ops(t_bench *bench);
const char	*strategy_label(t_strategy s);
const char	*complexity_label(t_strategy s);
void		put_percent(int fd, double ratio);
void		bench_count(t_bench *bench, t_countop code);
void		bench_init(t_bench *bench);
void		print_bench(t_bench *bench);
	//functions to run the choosen strat
t_strategy	apply_strat(t_flags *flags);
void		run_strat(t_strategy strategy, t_node **a, t_node **b, t_bench *bench);
//complex
int     *stack_to_array(t_node *a, int size);
void    sort_array(int *arr, int size);
int 	get_max_bits(t_node *a);
void    radix_sort(t_node **a, t_node **b, t_bench *bench);
int     stack_size(t_node *a);
// adaptive
t_strategy  select_adaptive(double disorder);
void	adaptive_sort(t_node **a, t_node **b, t_bench *bench);

#endif