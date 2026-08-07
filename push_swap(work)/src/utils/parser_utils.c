/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:33:50 by husobral          #+#    #+#             */
/*   Updated: 2026/08/06 11:51:18 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
    if (ft_strncmp(arg, "--bench", 8) == 0)
        return (1);
    return (0);
}

static void	set_strategy_flag(t_flags *flags, t_strategy s)
{
    flags->simple = false;
    flags->medium = false;
    flags->complex = false;
    flags->adaptive = false;
    if (s == SIMPLE)
        flags->simple = true;
    else if (s == MEDIUM)
        flags->medium = true;
    else if (s == COMPLEX)
        flags->complex = true;
    else
        flags->adaptive = true;
}

int check_flags(int argc, char **argv, t_flags *flags)
{
    int i;

    i = 1;
    flags->bench = false;
    flags->simple = false;
    flags->medium = false;
    flags->complex = false;
    flags->adaptive = false;
    while(i < argc && is_strategy_flag(argv[i]))
    {
        if(ft_strncmp(argv[i], "--bench", 8) == 0)
            flags->bench = true;
        else
            set_strategy_flag(flags, get_strategy(argv[i]));
        i++;
    }
    if(!flags->simple && !flags->medium && !flags->complex && !flags->adaptive)
        flags->adaptive = true;
    return (i);
}