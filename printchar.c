/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:34 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 13:31:01 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(t_format *fmt, char c)
{
	if (fmt->minus && fmt->width && fmt->specifier == 'c')
	{
		if (fmt-> width > 1)
		{
			write(1, &c, 1);
			ft_strset(fmt->width - 1, ' ');
			return (fmt->width);
		}
		else
			return (write(1, &c, 1));
	}
	else if (fmt->width &&fmt->minus == 0 && fmt->specifier == 'c')
	{
		if (fmt->width > 1)
		{
			ft_strset(fmt->width - 1, ' ');
			write(1, &c, 1);
			return (fmt->width);
		}
		else
			return (write(1, &c, 1));
	}	
	return (write(1, &c, 1));
}
