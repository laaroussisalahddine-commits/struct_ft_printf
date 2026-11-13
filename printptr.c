/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:25:52 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 16:35:03 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(t_format *fmt, unsigned long n)
{
	int	count;

	count = 0;
	count += ft_puts(fmt, "0x");
	print_lower_hex(fmt, n);
	return (lennumhex(n) + count);
}

int	ft_null(t_format *fmt)
{
	int skip;
	int count;

	count = 0;
	skip = 0;
	if (fmt->width > 5)
		skip = fmt->width - 5;
	if (fmt->width > 5 && fmt->minus && fmt->specifier == 'p')
	{
		count += ft_puts(fmt, "(nil)");
		ft_strset(skip, ' ');
	}
	else if (fmt->width > 5 && !fmt->minus && fmt->specifier == 'p')
	{
		ft_strset(skip, ' ');
		count += ft_puts(fmt, "(nil)");
	}
	else
		count += ft_puts(fmt, "(nil)");
	return (count + skip);
}

static int ft_call(t_format *fmt, unsigned long ptr, int skip)
{
	char	specf;
	int		count;

	count = 0;
	specf = fmt->specifier;
	if (fmt->width > lennumhex(ptr) + 2 && fmt->minus && specf == 'p')
	{
		count += ft_putptr(fmt, ptr);
		ft_strset(skip, ' ');
		return (skip + count);
	}
	if (fmt->width > lennumhex(ptr) + 2 && !fmt->minus && specf == 'p')
	{
		ft_strset(skip, ' ');
		count += ft_putptr(fmt, ptr);
		return (skip + count);
	}
	else if (fmt->width <= lennumhex(ptr) + 2 && specf == 'p')
		return (ft_putptr(fmt, ptr));
	return (0);
}

int	printptr(t_format *fmt, void *ptr)
{
	int				count;
	int				skip;
	unsigned long	a;

	if (!ptr)
		return (ft_null(fmt));
	a = (unsigned long)ptr;
	count = lennumhex(a);
	skip = 0;
	if (fmt->width > count + 2)
			skip = fmt->width - count - 2;
	if (fmt->minus || fmt->width) 
		return (ft_call(fmt, a, skip));
	else
		return (ft_putptr(fmt, a));
	return (count);
}
