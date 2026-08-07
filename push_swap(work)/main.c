/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:44 by husobral          #+#    #+#             */
/*   Updated: 2026/08/06 11:37:39 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

static void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d", stack->value);
		if (stack->next)
			printf(" ");
		stack = stack->next;
	}
	printf("\n");
}
t_strategy	apply_strat(t_flags *flags)
{
	if (flags->simple)
		return (SIMPLE);
	if (flags->medium)
		return (MEDIUM);
	if (flags->complex)
		return (COMPLEX)
	else
		return (ADAPTIVE);
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
	i = check_flags(argc, argv, &flags)
	if (i >= argc)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		return (0);
	b = NULL;
	strategy = apply_strat(&flags);
	// printf("Antes:\n");
	// printf("A: ");
	// print_stack(a);
	// printf("B: ");
	// print_stack(b);
	// printf("\nOperacoes:\n");
	// medium_sort(&a, &b);
	// printf("\nDepois:\n");
	// printf("A: ");
	// print_stack(a);
	// printf("B: ");
	// print_stack(b);
	// printf("Sorted: %d\n", is_sorted(a));
	// free_stack(&a);
	// free_stack(&b);
	// return (0);
}