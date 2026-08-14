/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:34:23 by husobral          #+#    #+#             */
/*   Updated: 2026/08/13 18:46:50 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_position(t_node *stack, t_node *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	move_to_top(t_node **a, t_node *target, t_bench *bench)
{
	int	pos;
	int	size;

	pos = get_position(*a, target);
	size = stack_size(*a);
	while (*a != target)
	{
		if (pos <= (size / 2))
			ra(a, bench);
		else
			rra(a, bench);
	}
}

void	move_to_top_b(t_node **b, t_node *target, t_bench *bench)
{
	int	pos;
	int	size;

	pos = get_position(*b, target);
	size = stack_size(*b);
	while (*b != target)
	{
		if (pos <= (size / 2))
			rb(b, bench);
		else
			rrb(b, bench);
	}
}
