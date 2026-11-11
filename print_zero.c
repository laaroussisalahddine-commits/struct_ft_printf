/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:22:26 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/10 22:29:43 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print_zeroo(t_format *fmt, int len, long n)
{
	int	skip;

	skip = 0;
	if (n >= 0 && fmt->plus)
		skip = fmt->width - len - 1;
	else
		skip = fmt->width - len;
	ft_call(skip, '0');
	printdecimal(n);
	return (skip + len);
}

static int		ft_add_minus(t_format *fmt, int len, long tmp)
{
	int	skip;
	int	count;

	count = 0;
	skip = 0;
	count += printchar('-');
	if (tmp > 0 && fmt->plus)
		skip = fmt->width - len - count;
	else
		skip = fmt->width - len - count;
	ft_call(skip, '0');
	printdecimal(tmp);
	return (skip + len + count);
}

int	print_zero_plus(t_format *fmt, long n)
{
	int		len_number;
	int		count;
	long	tmp;

	if (n < 0)
	{
		tmp = -n;
		len_number = lennumber(tmp);
	}
	else
		len_number = lennumber(n);
	count = 0;
	if (n >= 0 && fmt->width > len_number)
	{
		if (fmt->plus)
		{
			count += printchar('+');
			count += ft_print_zeroo(fmt, len_number, n);
		}
		else
			count += ft_print_zeroo(fmt, len_number, n);
	}
	else if (n < 0 && fmt->width > len_number + 1)
		count += ft_add_minus(fmt, len_number, tmp);
	else
	{
		if (n >= 0)
		{
			count += printchar('+');
			count += printdecimal(n);
		}
		else
			count += printdecimal(n);
	}
	return (count);
}
