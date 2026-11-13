/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:34 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 11:19:44 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(t_format *fmt, char c)
{
	if (fmt->minus)
	{
		if (fmt-> width > 1)
		{
			write(1, &c, 1);
			ft_call(fmt->width - 1, ' ');
			return (fmt->width);
		}
	}
	else
		return (write(1, &c, 1));
	return (-1);
}
