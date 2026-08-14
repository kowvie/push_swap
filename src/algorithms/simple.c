/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:31:41 by husobral          #+#    #+#             */
/*   Updated: 2026/08/13 18:42:45 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	simple_sort(t_node **a, t_node **b, t_bench *bench)
{
	t_node	*min;

	if (is_sorted(*a))
		return ;
	while (*a != NULL)
	{
		min = find_min_node(*a);
		move_to_top(a, min, bench);
		pb(a, b, bench);
	}
	while (*b != NULL)
	{
		pa(a, b, bench);
	}
}
