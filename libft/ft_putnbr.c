/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husobral <husobral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 14:01:04 by jsilva-r          #+#    #+#             */
/*   Updated: 2026/08/13 18:04:56 by husobral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_nbr(int fd, long n)
{
	char	buf[32];
	int		i;
	int		neg;

	i = 0;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	if (n == 0)
		buf[i++] = '0';
	while (n > 0)
	{
		buf[i++] = '0' + (n % 10);
		n = n / 10;
	}
	if (neg)
		buf[i++] = '-';
	while (i > 0)
		write(fd, &buf[--i], 1);
}
