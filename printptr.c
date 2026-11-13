/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:25:52 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 11:32:46 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printptr(t_format *fmt, void *ptr)
{
	int		count;
	long	a;

	a = (long)ptr;
	count = lennumhex(a);
	if (!ptr)
		return (printstring(fmt, "(nil)"));
	count += printstring(fmt, "0x");
	printhex(fmt, a, 0);
	return (count);
}
