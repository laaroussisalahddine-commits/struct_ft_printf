/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:50 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/13 11:32:03 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstring(t_format *fmt, char*s)
{
	int	i;
	(void)fmt;

	if (!s)
	{
		write (1, "(null)\n", 6);
		return (6);
	}
	i = 0;
	while (s[i])
		printchar(fmt, s[i++]);
	return (lenstring(s));
}
