/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:50 by husobral          #+#    #+#             */
/*   Updated: 2026/08/05 11:33:50 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_strategy get_strategy(char *arg)
{
    if (!arg)
        return (ADAPTIVE);
    if (ft_strncmp(arg, "--simple", 9) == 0)
        return (SIMPLE);
    if (ft_strncmp(arg, "--medium", 9) == 0)
        return (MEDIUM);
    if (ft_strncmp(arg, "--complex", 10) == 0)
        return (COMPLEX);
    if (ft_strncmp(arg, "--adaptive", 11) == 0)
        return (ADAPTIVE);
    return(ADAPTIVE);
}

int is_strategy_flag(char *arg)
{
    if (ft_strncmp(arg, "--simple", 9) == 0)
        return (1);
    if (ft_strncmp(arg, "--medium", 9) == 0)
        return (1);
    if (ft_strncmp(arg, "--complex", 10) == 0)
        return (1);
    if (ft_strncmp(arg, "--adaptive", 11) == 0)
        return (1);
    return (0);
}

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

t_strategy  select_adaptive(double disorder)
{
    if (disorder < 0.2)
        return (SIMPLE);
    if (disorder < 0.5)
        return (MEDIUM);
    return (COMPLEX);
}