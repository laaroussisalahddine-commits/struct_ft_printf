/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:42:17 by slaarous          #+#    #+#             */
/*   Updated: 2026/10/30 22:42:16 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initial_format(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->hash = 0;
	fmt->plus = 0;
	fmt->spaces = 0;
	fmt->width = 0;
	fmt->percision = 0;
	fmt->has_percision = 0;
	fmt->specifier = '\0';

}

int	is_specifier(char s)
{
	return(s == 'c' || s == 's' || s == 'd' 
			|| s == 'i' || s == 'u' || s == 'p' 
			|| s == 'x' || s == 'X' || s == '%');
}

void parse_format(const char *str, int *i, t_format *fmt)
{
	initial_format(fmt);
	while (str[*i] && !is_specifier(fmt->specifier))
	{
		if (str[*i] == '-')
			fmt->minus = 1;
		else if (str[*i - 1] == '%' && str[*i] == '0')
			fmt->zero = 1;
		else if (str[*i] == '#')
			fmt->hash = 1;
		else if (str[*i] == '+')
			fmt->plus = 1;
		else if (str[*i] == ' ')
			fmt->spaces = 1;
		else if (!(str[*i - 1] == '%') && (str[*i] >= '0' && str[*i] <= '9'))
			fmt->width = fmt->width * 10 + (str[*i] - '0');
		else if (str[*i] == '.')
			fmt->has_percision = 1;
		else if (fmt->has_percision && (str[*i] >= '0' && str[*i] <= '9'))
			fmt->percision = fmt->percision * 10 + (str[*i] - '0');
		else if (is_specifier(str[*i]))
			fmt->specifier = str[*i];
		*(i)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_format fmt;
	int		count;

}
