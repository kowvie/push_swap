/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:44 by husobral          #+#    #+#             */
/*   Updated: 2026/08/13 17:37:06 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_strategy	apply_strat(t_flags *flags)
{
	if (flags->simple)
		return (SIMPLE);
	if (flags->medium)
		return (MEDIUM);
	if (flags->complex)
		return (COMPLEX);
	else
		return (ADAPTIVE);
}
void	run_strat(t_strategy strategy, t_node **a, t_node **b, t_bench *bench)
{
	bench->requested = strategy;
	bench->executed = strategy;
	if (strategy == SIMPLE)
		simple_sort(a, b, bench);
	else if (strategy == MEDIUM)
		medium_sort(a, b, bench);
	else if (strategy == COMPLEX)
		radix_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_strategy	strategy;
	t_flags	flags;
	t_bench	bench;
	int	i;

	if (argc < 2)
		return (0);
	i = check_flags(argc, argv, &flags);
	if (i >= argc)
		return (0);
	a = parse_args(argc, argv, i);
	if (!a)
		return (0);
	b = NULL;
	strategy = apply_strat(&flags);
	bench_init(&bench);
	bench.active = flags.bench;
	bench.disorder = compute_disorder(a);
	run_strat(strategy, &a, &b, &bench);
	print_bench(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
