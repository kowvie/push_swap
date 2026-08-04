/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:29:42 by husobral          #+#    #+#             */
/*   Updated: 2026/07/30 13:42:55 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_node **src, t_node **dest)
{
    t_node  *node;

    if (!src || !*src || !dest)
        return ;
    node = *src;
    *src = node->next;
    if (*src)
        (*src)->prev = NULL;
    if (*dest)
        (*dest)->prev = node;
    node->prev = NULL;
    node->next = *dest;
    *dest = node;
}

void    pa(t_node **a, t_node **b)
{
    if (!a || !b || !*b)
        return ;
    push(b, a);
    print_op("pa");
}

void    pb(t_node **a, t_node **b)
{
    if (!b || !a || !*a)
        return ;
    push(a, b);
    print_op("pb");
}