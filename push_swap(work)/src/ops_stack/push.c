/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:32:45 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 11:32:45 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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