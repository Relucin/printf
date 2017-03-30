/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/30 03:04:35 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
typedef enum	e_flag
{
	ALT = 1,
	ZER = 2,
	NEG = 4,
	SPC = 8,
	PLS = 16
}				t_flag;

typedef enum	e_length
{
	hh = 1,
	h = 2,
	l = 3,
	ll = 4,
	j = 5,
	z = 6,
	L = 7
}				t_length;

typedef struct	s_part
{
	char			*str;
	unsigned char	flags;
	unsigned char	prec : 1;
	int		arg;
	int		width;
	int		pmin;
	int		length;
	int		type;
}				t_part;

typedef struct	s_args
{
	va_list ap;
	va_list *aps;
}								t_args;
typedef int (*t_check)(const char **, t_part *);

#endif
