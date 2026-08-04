/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:29:42 by husobral          #+#    #+#             */
/*   Updated: 2026/07/30 13:42:55 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

static void	print_strategy(t_strategy strategy)
{
	if (strategy == SIMPLE)
		printf("Strategy: SIMPLE\n");
	else if (strategy == MEDIUM)
		printf("Strategy: MEDIUM\n");
	else if (strategy == COMPLEX)
		printf("Strategy: COMPLEX\n");
	else
		printf("Strategy: ADAPTIVE\n");
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_strategy	strategy;
	double		disorder;

	if (argc < 2)
		return (0);
	strategy = get_strategy(argv[1]);
	a = parse_args(argc, argv);
	if (!a)
		return (0);
	disorder = compute_disorder(a);
	printf("Disorder: %.2f\n", disorder);
	if (strategy == ADAPTIVE)
		strategy = select_adaptive(disorder);
	print_strategy(strategy);
	free_stack(&a);
	return (0);
}