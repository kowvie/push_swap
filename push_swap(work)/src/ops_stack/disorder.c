/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:40:44 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/06 11:51:06 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
 
// double	compute_disorder(t_node *a)
// {
// 	t_node	*i;
// 	t_node	*j;
// 	long	mistakes;
// 	long	total_pairs;
 
// 	mistakes = 0;
// 	total_pairs = 0;
// 	i = a;
// 	while (i)
// 	{
// 		j = i->next;
// 		while (j)
// 		{
// 			total_pairs++;
// 			if (i->value > j->value)
// 				mistakes++;
// 			j = j->next;
// 		}
// 		i = i->next;
// 	}
// 	if (total_pairs == 0)
// 		return (0.0);
// 	return ((double)mistakes / (double)total_pairs);
// }
 
double  compute_disorder(t_node *a)
{
    t_node  *current;
    t_node  *compare;
    int mistakes;
    int total_pairs;

    mistakes = 0;
    total_pairs = 0;
    current = a;

    while (current)
    {
        compare = current->next;
        while (compare)
        {
            total_pairs++;
            if (current->value > compare->value)
                mistakes++;
            compare = compare->next;
        }
        current = current->next;
    }
    if (total_pairs == 0)
        return (0.0);
    return ((double)mistakes / total_pairs);
}