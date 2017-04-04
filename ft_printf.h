/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/03 23:20:49 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include "ftpf_dintarray.h"
# include <stdarg.h>

typedef enum		e_flag
{
	ALT = 1,
	ZER = 2,
	NEG = 4,
	SPC = 8,
	PLS = 16
}					t_flag;

typedef enum		e_length
{
	hh = 1,
	h = 2,
	l = 3,
	ll = 4,
	j = 5,
	z = 6,
	L = 7
}					t_length;

typedef struct		s_gpart
{
	unsigned char	prec : 1;
	void			*data;
}					t_gpart;

typedef struct		s_part
{
	unsigned char	flags;
	unsigned char	prec : 1;
	int				arg;
	int				width;
	int				pmin;
	int				length;
	char			type;
}					t_part;

typedef void		(*t_parse)(t_part *, va_list, int *);
int					ft_printf(const char *format, ...);
void				ftfp_string(t_part *token, va_list ap, int *n);
#endif
