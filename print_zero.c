/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:22:26 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/10 15:37:25 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_minus(int count, long n)
{
	char	*new;
	char	*string;

	string = ft_itoa(n);
	string[0] = '-';
	return (string);
}

int	print_zero(t_format *fmt, long n)
{
	int	len_number;
	int	skip;
	int	tmp;

	if (n < 0)
	{
		tmp = -n;
		len_number = lennumber(tmp);
	}
	else
		len_number(n);
	skip = 0;
	if (fmt->width > len_number)
	{
		skip = fmt->width - len_number;
		ft_call(skip , '0');		
	}
	else
		printdecimal(n);
	if (n < 0)
	{
		
	}
}