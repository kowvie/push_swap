/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 09:46:10 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/13 18:41:29 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_strategy	select_adaptive(double disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	adaptive_sort(t_node **a, t_node **b, t_bench *bench)
{
	t_strategy	chosen;

	chosen = select_adaptive(bench->disorder);
	bench->executed = chosen;
	if (chosen == SIMPLE)
		simple_sort(a, b, bench);
	else if (chosen == MEDIUM)
		medium_sort(a, b, bench);
	else
		radix_sort(a, b, bench);
}
