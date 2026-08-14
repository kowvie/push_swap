/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:21:53 by husobral          #+#    #+#             */
/*   Updated: 2026/08/13 18:41:57 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_indexes(t_node *stack)
{
	t_node	*current;
	t_node	*min;
	int		index;

	current = stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
	index = 0;
	min = find_unindexed_min(stack);
	while (min)
	{
		min->index = index;
		index++;
		min = find_unindexed_min(stack);
	}
}

int	int_sqrt(int n)
{
	int	i;

	i = 0;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}
