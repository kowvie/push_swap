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

void    print_op(char *op)
{
    write(1, op, ft_strlen(op));
    write(1, "\n", 1);
}

void    swap(t_node **stack)
{
    t_node *first;
    t_node *second;

    if (!stack || !*stack || !(*stack)->next)
        return ;

    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
    second->prev = NULL;
    first->prev = second;
    if (first->next)
        first->next->prev = first;
    return ;
}

void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
    print_op("ss");
}

void    sa(t_node **a)
{
    swap(a);
    print_op("sa");
}

void    sb(t_node **b)
{
    swap(b);
    print_op("sb");
}
