/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:29:42 by husobral          #+#    #+#             */
/*   Updated: 2026/08/06 11:35:14 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	new->index = -1;
	return (new);
}

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

void	stack_add_front(t_node **stack, t_node *new)
{
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	new->prev = NULL;
	(*stack)->prev = new;
	*stack = new;
}

void	stack_add_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = last_node(*stack);
	last->next = new;
	new->prev = last;
}

t_node	*find_max_node(t_node	*stack)
{
	t_node	*max_node;
	
	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (max_node->value < stack->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}