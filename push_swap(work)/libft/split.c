/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 12:33:56 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/13 16:05:20 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	words_enumerator(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*word_splitter(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**revolucion(char **words, int j)
{
	while (j >= 0)
	{
		free(words[j]);
		j--;
	}
	free(words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = (char **) malloc(sizeof(char *) * (words_enumerator(s, c) + 1));
	if (!words || !s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			words[j] = word_splitter(&s[i], c);
			if (!words[j])
				return (revolucion(words, j));
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}
// end of split
int check_string(char *str)
{
    int i = 0;

    if (!str)
        return (write(1, "empty", 5), 0);
    if (str[i] == '-' || str[i] == '+')
        i++;    
    while (str[i] != '\0')
    {
        if (str[i] > 47 && str[i] < 58)
            i++;
        else
            return ((write(1, "not numeric", 11), 0));
    }
    return (1);
}
void    free_split(char **numbers)
{
    int i = 0;
    while (numbers[i])
    {
        free(numbers[i]);
        i++;
    }
    free(numbers);
}

t_node *check_split(char *str)
{
    char **numbers;
	long	value;
	t_node 	*new;
	t_node 	*a;
	
    numbers = ft_split(str, ' ');
    int i = 0;
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
