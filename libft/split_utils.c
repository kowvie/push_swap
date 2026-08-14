/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 17:41:08 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/14 20:03:24 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

t_node	*check_split(char *str, int i)
{
	char	**numbers;
	long	value;
	t_node	*new;
	t_node	*a;

	numbers = ft_split(str, ' ');
	i = 0;
	a = NULL;
	new = NULL;
	if (numbers[i] == NULL)
		return (printf("error\n"), free_split(numbers), NULL);
	while (numbers[i] != NULL)
	{
		if (!is_valid_number(numbers[i]) || !is_int_range(numbers[i]))
			error_free(&a);
		value = ft_atol(numbers[i]);
		if (has_duplicate(a, (int)value))
			error_free(&a);
		new = new_node((int)value);
		if (!new)
			return (free_stack(&a), NULL);
		stack_add_back(&a, new);
		i++;
	}
	return (free_split(numbers), a);
}
