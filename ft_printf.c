/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:42:17 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/10 21:30:56 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(const char *str, int *i, t_format *fmt)
{
	while (is_flags(str[*i]))
	{
		if (str[*i] == '-')
			fmt->minus = 1;
		else if (str[*i] == '0')
			fmt->zero = 1;
		else if (str[*i] == '#')
			fmt->hash = 1;
		else if (str[*i] == '+')
			fmt->plus = 1;
		else if (str[*i] == ' ')
			fmt->spaces = 1;
		(*i)++;
	}
}

void	parse_format(const char *str, int *i, t_format *fmt)
{
	initial_format(fmt);
	Flags(str, i, fmt);
	while (str[*i] >= '0' && str[*i] <= '9')
		fmt->width = fmt->width * 10 + (str[(*i)++] - '0');
	if (str[*i] == '.')
	{
		fmt -> has_percision = 1;
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
			fmt->percision = fmt->percision * 10 + (str[(*i)++] - '0');
	}
	if (is_specifier(str[*i]))
		fmt->specifier = str[(*i)++];
}

int	print_format(va_list args, t_format *fmt, int *i)
{
	int	count;

	count = 0;
	if (fmt->specifier == 'c')
		count += printchar(va_arg(args, int));
	else if (fmt->specifier == 's')
		count += printstring(va_arg(args, char *));
	else if (fmt->specifier == 'd' || fmt->specifier == 'i')
		count += printdecimal(va_arg(args, int));
	else if (fmt->specifier == 'x')
		count += printhex(va_arg(args, unsigned int), 0);
	else if (fmt->specifier == 'X')
		count += printhex(va_arg(args, unsigned int), 1);
	else if (fmt->specifier == 'p')
		count += printptr(va_arg(args, void *));
	else if (fmt->specifier == 'u')
		count += printuns(va_arg(args, unsigned int));
	else if (fmt->specifier == '%')
		count += printchar('%');
	(*i)++;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_format fmt;
	int	count;
	int	i;

	if (!str || (str[0] == '%' && str[1] == '\0'))
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		initial_format(&fmt);
		while (str[i] && str[i] != '%')
			count += printchar(str[i++]);
		if (str[i] == '%')
		{
			i++;
			while (is_flags(&fmt) || ft_isdigits(str[i]))
				parse_format(str, &i, &fmt);
			count += print_format(args, &fmt, &i);
		}
	}
	va_end(args);
	return (count);
}
