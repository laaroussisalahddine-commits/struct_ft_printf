/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:36:06 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 11:32:36 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_lower_hex(t_format *fmt, unsigned long n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		print_lower_hex(fmt, n / 16);
	printchar(fmt, hex[n % 16]);
}

void	print_upper_hex(t_format *fmt, unsigned long n)
{
	char	*hex;	

	hex = "0123456789ABCDEF";
	if (n >= 16)
		print_upper_hex(fmt, n / 16);
	printchar(fmt, hex[n % 16]);
}

int	printhex(t_format *fmt, unsigned int x, int upper)
{
	int				count;
	unsigned long	n;

	n = x;
	count = lennumhex(n);
	if (fmt->hash && upper == 0)
	{
		if (n == 0)
			return (printdecimal(fmt ,0));
		count += printstring(fmt, "0x");
		print_lower_hex(fmt, n);
		return (count);
	}
	if (!fmt->hash && upper == 1)
		print_upper_hex(fmt, n);
	else if (!fmt->hash && upper == 0)
		print_lower_hex(fmt, n);
	else
		return (-1);
	return (count);
}
