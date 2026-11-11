/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaarous <slaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:26:04 by slaarous          #+#    #+#             */
/*   Updated: 2026/11/10 22:14:57 by slaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format
{
	int		minus;
	int		zero;
	int		hash;
	int		plus;
	int		spaces;
	int		width;
	int		percision;
	int		has_percision;
	char	specifier;
}		t_format;

/* print format */
int				printdecimal(int x);
int				printchar(char c);
int				printstring(char *s);
int				printuns(long x);
int				printhex(unsigned int n, int upper);
int				printptr(void *ptr);

/* count number */
unsigned int	lennumhex(unsigned long n);
int				lenstring(char *s);
int				lennumber(long n);

/* main function */
int				ft_printf(const char *str, ...);

/* bonus */
int				print_hash(unsigned long n , int upper);
int				print_padding(t_format *fmt, long n);
int				ft_ze_pl(t_format *fmt, long n);

/* helper */
int				is_flags(char c);
int				is_specifier(char s);
void			initial_format(t_format *fmt);
void			ft_call(int len, char c);

#endif