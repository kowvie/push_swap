/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:31:41 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 13:58:44 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    simple_sort(t_node **a, t_node **b)
{
    t_node  *min;
    
    if (is_sorted(*a))
        return ;
    while (*a != NULL)
    {
        min = find_min_node(*a);
        move_to_top(a, min);
        pb(a, b);
    }
    while (*b != NULL)
    {
        pa (a, b);
    }
}