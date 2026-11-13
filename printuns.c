/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:54 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 18:05:15 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuns(t_format *fmt, unsigned long n)
{
	int count;

	count = lennumber(n);
	if (n >= 10)
		ft_putuns(fmt, n / 10);
	printchar(fmt, (n % 10) + '0');
	return (count);
}
static int	ft_call(t_format *fmt, unsigned long n, int len, int skip)
{
	char	specf;
	int		count;

	count = 0;
	specf = fmt->specifier; 
	if (fmt->width > len && fmt->minus && specf == 'u')
	{
		count += ft_putuns(fmt, n);
		ft_strset(skip, ' ');
	}
	else if (fmt->width > len && !fmt->minus && specf == 'u')
	{
		if (fmt->zero)
			ft_strset(skip, '0');
		else	
			ft_strset(skip, ' ');
		count += ft_putuns(fmt, n);
	}
	else if (fmt->width <= len && specf == 'u')
		return (ft_putuns(fmt, n));
	return (count + skip);
}

int	printuns(t_format *fmt, unsigned int x)
{
	unsigned long n;
	int	count;
	int	skip;

	skip = 0;
	n = x;
	count = lennumber(n);
	if (fmt->width > count)
	{
		skip = fmt->width - count;
		return (ft_call(fmt, n, count, skip));
	}
	return (ft_putuns(fmt, n));
}
