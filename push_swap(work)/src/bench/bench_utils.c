/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:03:58 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/07 14:03:58 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    print_op_count(t_bench *bench, int op, const char *name)
{
    put_str(2, name);
    put_nbr(2, bench->counts[op]);
}

void    print_ops(t_bench *bench)
{
    static const char *names[] = {
        "sa: ", " sb: ", " ss: ", " pa: ", " pb: ",
        "ra: ", " rb: ", " rr: ", " rra: ", " rrb: ", " rrr: "
    };
    int i;

    put_str(2, "[bench] ");
    i = 0;
    while (i < 11)
    {
        if (i == 5)
            put_str(2, "\n[bench] ");
        print_op_count(bench, i, names[i]);
        i++;
    }
    put_str(2, "\n");
}
const char	*strategy_label(t_strategy s)
{
	if (s == SIMPLE)
		return ("Simple");
	if (s == MEDIUM)
		return ("Medium");
	if (s == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

const char	*complexity_label(t_strategy s)
{
	if (s == SIMPLE)
		return ("O(n2)");
	if (s == MEDIUM)
		return ("O(n\xe2\x88\x9an)");
	return ("O(n log n)");
}
void	put_percent(int fd, double ratio)
{
	long	hundredths;

	hundredths = (long)(ratio * 10000.0 + 0.5);
	put_nbr(fd, hundredths / 100);
	put_str(fd, ".");
	if (hundredths % 100 < 10)
		put_str(fd, "0");
	put_nbr(fd, hundredths % 100);
	put_str(fd, "%\n");
}