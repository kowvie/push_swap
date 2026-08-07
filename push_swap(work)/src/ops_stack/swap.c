/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:19 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 11:33:19 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void    ss(t_node **a, t_node **b, t_bench *bench)
{
    swap(a);
    swap(b);
    print_op("ss");
    bench_count(bench, OP_SS);
}

void    sa(t_node **a, t_bench *bench)
{
    swap(a);
    print_op("sa");
    bench_count(bench, OP_SA);
}

void    sb(t_node **b, t_bench *bench)
{
    swap(b);
    print_op("sb");
    bench_count(bench, OP_SB);
}
