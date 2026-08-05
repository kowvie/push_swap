/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:32:53 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 11:32:53 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    reverse_rotate(t_node **stack)
{
    t_node  *last;
    
    if (!stack || !*stack || !(*stack)->next)
        return ;
    last = last_node(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
    last->prev = NULL;
}

void    rra(t_node **a)
{
    if (!a || !*a || !(*a)->next)
        return ;
    reverse_rotate(a);
    print_op("rra");
}

void    rrb(t_node **b)
{
    if (!b || !*b || !(*b)->next)
        return ;
    reverse_rotate(b);
    print_op("rrb");
}

void    rrr(t_node **a, t_node **b)
{
    if ((!a || !*a || !(*a)->next) && (!b || !*b || !(*b)->next))
        return ;
    reverse_rotate(a);
    reverse_rotate(b);
    print_op("rrr");
}