/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 14:08:32 by husobral          #+#    #+#             */
/*   Updated: 2026/08/13 18:42:24 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*find_unindexed_min(t_node *stack)
{
	t_node	*min;

	min = NULL;
	while (stack)
	{
		if (stack->index == -1)
		{
			if (min == NULL || stack->value < min->value)
				min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

static void	push_chunks(t_node **a, t_node **b, int chunk_size, t_bench *bench)
{
	int	limit;
	int	pushed;

	limit = chunk_size;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b, bench);
			pushed++;
			if (pushed == limit)
				limit += chunk_size;
		}
		else
			ra(a, bench);
	}
}

static void	push_back_sorted(t_node **a, t_node **b, t_bench *bench)
{
	t_node	*max;

	while (*b)
	{
		max = find_max_index(*b);
		move_to_top_b(b, max, bench);
		pa(a, b, bench);
	}
}

void	medium_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	chunk_size;

	if (is_sorted(*a))
		return ;
	assign_indexes(*a);
	size = stack_size(*a);
	chunk_size = int_sqrt(size);
	push_chunks(a, b, chunk_size, bench);
	push_back_sorted(a, b, bench);
}

t_node	*find_max_index(t_node *stack)
{
	t_node	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (max->index < stack->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}
