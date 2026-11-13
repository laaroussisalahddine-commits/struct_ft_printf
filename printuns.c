/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:54 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 11:27:13 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_long(t_format *fmt, unsigned long n)
{
	if (n >= 10)
		put_long(fmt, n / 10);
	printchar(fmt, (n % 10) + '0');
}

int	printuns(t_format *fmt, unsigned int x)
{
	unsigned long n;
	int	count;

	n = x;
	count = lennumber(n);
	put_long(fmt, n);
	return (count);
}
