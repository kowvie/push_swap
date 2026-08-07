/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilva-r <jsilva-r@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:04:01 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/07 14:04:01 by jsilva-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bench_count(t_bench *bench, t_opcode code)
{
	if (!bench || code < 0 || code >= OP_COUNT)
		return ;
	bench->counts[code]++;
	bench->total++;
}
void	bench_init(t_bench *bench)
{
	int	i;

	i = 0;
	bench->active = 0;
	bench->total = 0;
	bench->disorder = 0.0;
	bench->requested = ADAPTIVE;
	bench->executed = ADAPTIVE;
	while (i < OP_COUNT)
	{
		bench->counts[i] = 0;
		i++;
	}
}
void print_bench(t_bench *bench)
{
    if (!bench || !bench->active)
        return;

    put_str(2, "[bench] disorder: ");
    put_percent(2, bench->disorder);
    put_str(2, "[bench] strategy: ");

    if (bench->requested == ADAPTIVE)
        put_str(2, "Adaptive");
    else
        put_str(2, strategy_label(bench->requested));

    put_str(2, " / ");
    put_str(2, complexity_label(bench->executed));
    put_str(2, "\n");

    put_str(2, "[bench] total_ops: ");
    put_nbr(2, bench->total);
    put_str(2, "\n");

    print_ops(bench);
}