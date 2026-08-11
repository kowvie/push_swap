/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:56 by husobral          #+#    #+#             */
/*   Updated: 2026/08/11 12:02:14 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int is_valid_number(char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

long    ft_atol(const char *str)
{
    long    nbr;
    int     sign;
    int     i;

    nbr = 0;
    sign = 1;
    i = 0;
    if(str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (nbr > 214748364 || (nbr == 214748364 && str[i] - '0' > 8))
            return (2147483649 * sign);
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return (sign * nbr);
}

int     is_int_range(char *str)
{
    long    nbr;

    nbr = ft_atol(str);
    if (nbr > 2147483647 || nbr < -2147483648)
        return (0);
    return (1);
}

int     has_duplicate(t_node *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (1);
        stack = stack->next;
    }
    return (0);
}

t_node  *parse_args(int argc, char **argv, int start)
{
    t_node  *a;
    t_node  *new;
    int     i;
    long    value;

    a = NULL;
    i = start;
    while(i < argc)
    {
        if (!is_valid_number(argv[i]))
            error_free(&a);
        if (!is_int_range(argv[i]))
            error_free(&a);
        value = ft_atol(argv[i]);
        if (has_duplicate(a, (int)value))
            error_free(&a);
        new = new_node((int)value);
        if (!new)
            return (free_stack(&a), NULL);
        stack_add_back(&a, new);
        i++;
    }
    return (a);
}
