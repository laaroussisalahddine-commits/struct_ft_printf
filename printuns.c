/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:54 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/28 17:36:39 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_long(unsigned long n)
{
	if (n >= 10)
		put_long(n / 10);
	printchar((n % 10) + '0');
}

int	printuns(unsigned int x)
{
	unsigned long n;
	int	count;

	n = x;
	count = lennumber(n);
	put_long(n);
	return (count);
}
