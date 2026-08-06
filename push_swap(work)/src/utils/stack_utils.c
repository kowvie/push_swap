/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:34:05 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 11:34:05 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_node *stack)
{
    int i;

    i = 0;
    while(stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

int    is_sorted(t_node *stack)
{
    while(stack && stack->next)
    {
        if(stack->value > stack->next->value)
            {
                return (0);
            }
        stack = stack->next;
    }
    return (1);
}

int find_min(t_node *stack)
{
    int min;

    min = stack->value;
    while(stack)
    {
        if (min > stack->value)
            min = stack->value;
        stack = stack->next;
    }
    return(min);
}

int find_max(t_node *stack)
{
    int max;

    max = stack->value;
    while (stack)
    {
        if (max < stack->value)
            max = stack->value;
        stack = stack->next;
    }
    return(max);
}

t_node  *find_min_node(t_node *stack)
{
    t_node *min_node;

    if (!stack)
        return (NULL);
    min_node = stack;
    while(stack)
    {
        if (min_node->value > stack->value)
            min_node = stack;
        stack = stack->next;
    }
    return(min_node);
}