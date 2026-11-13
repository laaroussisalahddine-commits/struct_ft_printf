/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:50 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 13:43:31 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puts(t_format *fmt, char *s)
{
	int	i;

	i = 0;
	while (s[i])
		printchar(fmt, s[i++]);
	return (lenstring(s));
}

static int	ft_call(t_format *fmt, char *s, int skip)
{
	if (fmt->width > lenstring(s) && fmt->minus && fmt->specifier == 's')
	{
		if (skip != 0)
			ft_puts(fmt, s);
		ft_strset(skip, ' ');
		return (skip + lenstring(s));
	}
	else if (fmt->width > lenstring(s) && !fmt->minus && fmt->specifier == 's')
	{
		if (skip != 0)
			ft_strset(skip, ' ');
		ft_puts(fmt, s);
		return (skip + lenstring(s));
	}
	else if (fmt->width < lenstring(s) && fmt->specifier == 's')
		return (ft_puts(fmt, s));
	return (0);
}

int	printstring(t_format *fmt, char* s)
{
	int	skip;
	int	count;

	if (!s)
	{
		write (1, "(null)\n", 6);
		return (6);
	}
	count = 0;
	skip = 0;
	if (fmt->minus || fmt->width)
	{
		if (fmt->width > lenstring(s))
			skip = fmt->width - lenstring(s);
		count += ft_call(fmt, s, skip);
	}
	else
		return (ft_puts(fmt, s));
	return (count);
}
