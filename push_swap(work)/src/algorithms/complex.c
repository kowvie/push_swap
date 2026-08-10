/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 15:21:53 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 15:38:03 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int     *stack_to_array(t_node *a, int size)
// {
//     int *arr;
//     t_node *tmp;
//     int i;

//     if(!a || size <= 0)
//         return (NULL);
//     arr = malloc(sizeof(int) * size);
//     if (!arr)
//         return (NULL);
//     tmp = a;
//     i = 0;
//     while (tmp)
//     {
//         arr[i] = tmp->value;
//         tmp = tmp->next;
//         i++;
//     }
//     return (arr);
// }



// void    sort_array(int *arr, int size)
// {
//     int i;
//     int j;
//     int tmp;

//     i = 0;
//     while (i < size - 1)
//     {
//         j = 0;
//         while(j < size - i - 1)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 tmp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = tmp;
//             }
//             j++;
//         }
//         i++;
//     }
// }
// void    assign_index(t_node *a, int *sorted, int size)
// {
//     t_node *tmp;
//     int i;

//     tmp = a;
//     while (tmp)
//     {
//         i = 0;
//         while (i < size)
//         {
//             if (tmp->value == sorted[i])
//             {
//                 tmp->index = i;
//                 break ;
//             }
//             i++;
//         }
//         tmp = tmp->next;
//     }
// }
int stack_size(t_node *a)
{
    int size;

    size = 0;
    while (a)
    {
        size++;
        a = a->next;
    }
    return (size);
}

int get_max_bits(t_node *a)
{
    int max;
    int bits;

    max = 0;
    while (a)
    {
        if (a->index > max)
            max = a->index;
        a = a->next;
    }
    bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return (bits);
}

void    radix_sort(t_node **a, t_node **b, t_bench *bench)
{
    int i;
    int j;
    int max_bits;
    int size;

    max_bits = get_max_bits(*a);
    size = stack_size(a);
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            if (((*a)->index >> i) & 1)
                ra(a, bench);
            else
                pb(a, b, bench);
            j++;
        }
        while (*b)
            pa(a, b, bench);
        i++;
    }
}