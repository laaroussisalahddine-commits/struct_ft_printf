/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:22:26 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 13:04:59 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_positive_padded(t_format *fmt, int len, long n)
{
	int	skip;
	int	count;

	skip = 0;
	if (n >= 0 && fmt->plus)
		skip = fmt->width - len - 1;
	else
		skip = fmt->width - len;
	count = 0;
	if (fmt->plus && fmt->zero == 0 && fmt->width > len)
	{
		ft_strset(skip, ' ');
		count += printchar(fmt, '+');
	}
	else
	{
		if ((fmt->plus && fmt->zero == 0) || (fmt->plus && fmt->zero))
			count += printchar(fmt, '+');
		ft_strset(skip, '0');
	}
	printdecimal(fmt, n);
	return (skip + len + count);
}

static int	print_negative_padded(t_format *fmt, int len, long tmp)
{
	int	skip;
	int	count;

	count = 0;
	skip = 0;
	if (fmt->width <= len)
		skip = fmt->width - len;
	else
		skip = fmt->width - len - 1;
	if (fmt->plus && fmt->zero == 0 && fmt->width > len - 1)
	{
		ft_strset(skip, ' ');
		count += printchar(fmt, '-');
	}
	else
	{
		count += printchar(fmt, '-');
		ft_strset(skip, '0');
	}
	printdecimal(fmt, tmp);
	return (skip + len + count);
}

static int	handle_plus_flag(t_format *fmt, int len_number, long n, long tmp)
{
	int	count;

	count = 0;
	if (n >= 0 && fmt->plus && fmt->width > len_number)
		count += print_positive_padded(fmt, len_number, n);
	else if (n < 0 && fmt-> plus && fmt->width > len_number - 1)
		count += print_negative_padded(fmt, len_number, tmp);
	else
	{
		if (n >= 0)
		{
			count += printchar(fmt, '+');
			count += printdecimal(fmt, n);
		}
		else
			count += printdecimal(fmt, n);
	}
	return (count);
}

static int	handle_zero_flag(t_format *fmt, int len_number, long n, long tmp)
{
	int	count;

	count = 0;
	if (n >= 0 && fmt->width > len_number)
		count += print_positive_padded(fmt, len_number, n);
	else if (n < 0 && fmt->width > len_number + 1)
		count += print_negative_padded(fmt, len_number, tmp);
	else
		count += printdecimal(fmt, n);
	return (count);
}

int	ft_ze_pl(t_format *fmt, long n)
{
	int		count;
	int		len_number;
	long	tmp;

	if (n < 0)
	{
		tmp = -n;
		len_number = lennumber(tmp);
	}
	else
		len_number = lennumber(n);
	count = 0;
	if (fmt->zero || fmt->plus)
	{
		if (fmt->plus)
			count += handle_plus_flag(fmt, len_number, n, tmp);
		else
			count += handle_zero_flag(fmt, len_number, n, tmp);
	}
	return (count);
}
