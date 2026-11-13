/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:38 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 11:23:08 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(t_format *fmt, long n)
{
	if (n >= 10)
		ft_putlong(fmt, n / 10);
	printchar(fmt, (n % 10) + '0');
}

int	printdecimal(t_format *fmt, int x)
{
	long	n;
	int		count;

	n = x;
	count = lennumber(n);
	if (n < 0)
	{
		printchar(fmt, '-');
		n = -n;
	}
	ft_putlong(fmt, n);
	return (count);
}
