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

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

void	print_stack_reverse(t_node *stack)
{
	t_node	*last;

	if (!stack)
		return ;
	last = last_node(stack);
	while (last)
	{
		printf("%d\n", last->value);
		last = last->prev;
	}
}

int	main(void)
{
	t_node	*a;

	a = NULL;
	stack_add_back(&a, new_node(10));
	stack_add_back(&a, new_node(20));
	stack_add_back(&a, new_node(30));
	stack_add_back(&a, new_node(40));

	printf("ANTES:\n");
	print_stack(a);

	reverse_rotate(&a);

	printf("\nDEPOIS REVERSE ROTATE - NEXT:\n");
	print_stack(a);

	printf("\nDEPOIS REVERSE ROTATE - PREV:\n");
	print_stack_reverse(a);

	return (0);
}