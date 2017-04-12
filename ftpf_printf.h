/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:41:27 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/11 19:35:08 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_PRINTF_H
# define FTPF_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft.h"

typedef enum	e_length
{
	hh = 1,
	h = 2,
	l = 4,
	ll = 8,
	j = 16,
	z = 32,
	L = 64
}				t_length;

typedef enum	e_flag
{
	ALT = 1,
	ZER = 2,
	NEG = 4,
	SPC = 8,
	PLS = 16
}				t_flag;

typedef struct	s_part
{
	uint64_t	width;
	uint64_t	prec;
	uint64_t	arg;
	uint8_t		flags;
	uint8_t		p;
	uint8_t		length;
	char		type;
}				t_part;

typedef char	*(*t_parse)(int *, va_list);
t_part			g_part;
bool			ftpf_checknums(const char **format, va_list ap);
bool			ftpf_checkprecision(const char **format, va_list ap);
bool			ftpf_checkflags(const char **format);
bool			ftpf_checklength(const char **format);

char			*ftpf_string(int *len, va_list ap);
char			*ftpf_wstos(wchar_t *str);
//TODO: Figure out how to split this up better?
void			ftpf_resetpart(void);
int				ftpf_parse(char **parts, const char *format, va_list ap);
char			*ftpf_gspart(const char **format, int *len, int *plen);
char			*ftpf_getstr(const char **format, int *len, va_list ap);
char			*ftpf_pad(char *str, int *len, size_t strl);
#endif
