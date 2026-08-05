/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:05 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 11:33:05 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_node **a)
{
    if (!a || !*a || !(*a)->next)
        return ;
    rotate(a);
    print_op("ra");
}

void    rb(t_node **b)
{
    if (!b || !*b || !(*b)->next)
        return ;
    rotate(b);
    print_op("rb");
}

void    rr(t_node **a, t_node **b)
{
    if ((!a || !*a  || !(*a)->next) && (!b || !*b || !(*b)->next))
        return ;
    rotate(a);
    rotate(b);
    print_op("rr");
}
void    rotate(t_node **stack)
{
    t_node  *first;
    t_node  *last;
    
    if(!stack || !*stack || !(*stack)->next)
        return ;
    last = last_node(*stack);
    first = *stack;
    *stack = first->next;
    (*stack)->prev = NULL;
    last->next = first;
    first->prev = last;
    first->next = NULL;
}