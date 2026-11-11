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
