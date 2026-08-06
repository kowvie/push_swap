/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:31:41 by husobral          #+#    #+#             */
/*   Updated: 2026/08/06 11:34:51 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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