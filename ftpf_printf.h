/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:41:27 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/15 21:58:12 by bmontoya         ###   ########.fr       */
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
	PLS = 16,
	X = 32
}				t_flag;

typedef struct	s_string
{
	char		*str;
	size_t		len;
}				t_string;

typedef struct	s_part
{
	uint64_t	width;
	uint64_t	prec;
	uint64_t	arg;
	uint8_t		flags;
	uint8_t		p;
	uint8_t		length;
	uint8_t		base;
	size_t		len;
	char		type;
}				t_part;

//TODO: These need to be placed into libft eventually...
char			*ft_ltoa_10(int64_t nbr);
char			*ft_ultoa_base(uint64_t nbr, int base);
void			ft_strupper(char *str);

typedef char	*(*t_parse)(size_t *, va_list);
t_part			g_part;
bool			ftpf_checknums(const char **format, va_list ap);
bool			ftpf_checkprecision(const char **format, va_list ap);
bool			ftpf_checkflags(const char **format);
bool			ftpf_checklength(const char **format);

char			*ftpf_string(size_t *len, va_list ap);
char			*ftpf_wstos(wchar_t *str);
int				ftpf_wtos(char *ret, wchar_t str);

// char			*ftpf_intflags(char *str, int *len, size_t *slen);
// char			*ftpf_ints(int *len, va_list ap);
// char			*ftpf_alt(char *str, int *len, size_t *slen);
//TODO: Figure out how to split this up better?
void			ftpf_resetpart(void);
int				ftpf_parse(t_string **parts, const char *format, va_list ap);
char			*ftpf_gspart(const char **format, size_t *len, int *plen);
char			*ftpf_getstr(const char **format, size_t *len, va_list ap);
char			*ftpf_pad(char *str, size_t *len, size_t strl);
#endif
