/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:26 by husobral          #+#    #+#             */
/*   Updated: 2026/08/06 11:35:27 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void    error_free(t_node **stack)
{
    free_stack(stack);
    write(2, "Error\n", 6);
    exit(1);
}