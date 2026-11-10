/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:13:11 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/10 21:44:00 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(t_format *fmt, long n)
{
	int	len_number;
	int	skip;

	len_number = lennumber(n);
	skip = 0;
	if (fmt->width > len_number && !fmt->minus)
	{
		skip = fmt-> width - len_number;
		ft_call(skip, ' ');
		printdecimal(n);
	}
	else if (fmt->width > len_number && fmt->minus)
	{
		skip = fmt-> width - len_number;
		printdecimal(n);
		ft_call(skip, ' ');
	}
	else
		printdecimal(n);
	return (skip + len_number);
}
