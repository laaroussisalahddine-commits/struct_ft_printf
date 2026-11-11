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
	int count;

	count = 0;
	skip = 0;
	if (n >= 0 && fmt->plus)
		skip = fmt->width - len - 1;
	else
		skip = fmt->width - len;
	if (fmt->plus && fmt->zero == 0 && fmt->width > len)
	{
		ft_call(skip, ' ');
		printchar('+');
	}
	else
	{
		if ((fmt->plus && fmt->zero == 0) || (fmt->plus && fmt->zero))
			count += printchar('+');
		ft_call(skip, '0');
	}
	printdecimal(n);
	return (skip + len + count);
}

static int		ft_add_minus(t_format *fmt, int len, long tmp)
{
	int	skip;
	int	count;

	count = 0;
	skip = 0;
	skip = fmt->width - len - 1;
	if (fmt->plus && fmt->zero == 0 && fmt->width > len - 1)
	{
		ft_call(skip, ' ');
		count += printchar('-');
	}
	else
	{
		count += printchar('-');
		ft_call(skip, '0');
	}
	printdecimal(tmp);
	return (skip + len + count);
}

static int	print_plus(t_format *fmt, long n)
{
	int	len_number;
	int	count;
	long tmp;

	if (n < 0)
	{
		tmp = -n;
		len_number = lennumber(tmp);
	}
	else
		len_number = lennumber(n);
	count = 0;
	if (n >= 0 && fmt-> plus && fmt->width > len_number)
		count += ft_print_zeroo(fmt, len_number, n);
	else if (n < 0 && fmt-> plus && fmt->width > len_number - 1)
		count += ft_add_minus(fmt, len_number, tmp);
	else
	{
		if (n >= 0)
		{
			count += printchar('+');
			count += printdecimal(n);
		}
		else
			printdecimal(n);
	}
	return (count);
}

static int	print_zero(t_format *fmt, long n)
{
	int	len_number;
	int	count;
	long tmp;

	if (n < 0)
	{
		tmp = -n;
		len_number = lennumber(tmp);
	}
	else
		len_number = lennumber(n);
	count = 0;
	if (n >= 0 && fmt->width > len_number)
		count += ft_print_zeroo(fmt, len_number, n);
	else if (n < 0 && fmt->width > len_number + 1)
		count += ft_add_minus(fmt, len_number, tmp);
	else
		count += printdecimal(n);
	return (count);
}
int	ft_ze_pl(t_format *fmt, long n)
{
	int	count;

	count = 0;
	if (fmt->zero || fmt->plus)
	{
		if (fmt->plus)
			count += print_plus(fmt, n);
		
		else
			count += print_zero(fmt, n);
	}
	return (count);
}