/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 12:33:56 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/07 12:33:56 by jsilva-r         ###   ########.fr       */
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

int check_split(char *str)
{
    char **numbers;
    numbers = ft_split(str, ' ');
    int i = 0;
    if (numbers[i] == NULL)
        return (printf("error\n"), free_split(numbers), 0);
    while (numbers[i] != NULL)
    {
            if (check_string(numbers[i]) == 0)
                return (printf("error\n"), free_split(numbers), 0);
            i++;
    }
    return (free_split(numbers), 1);
}
