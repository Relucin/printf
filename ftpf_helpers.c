/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:01:20 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/14 22:36:46 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

void	ft_strupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

char	*ft_ultoa_base(uint64_t nbr, int base)
{
	uint64_t	cpy;
	uint8_t		length;
	char		*ret;

	cpy = nbr;
	length = 0;
	while (cpy)
	{
		cpy /= base;
		++length;
	}
	if (!nbr)
		++length;
	ret = malloc(sizeof(*ret) * (length + 1));
	ret[length--] = '\0';
	if (!nbr)
		ret[0] = '0';
	while (nbr)
	{
		ret[length--] = "0123456789abcdef"[nbr % base];
		nbr /= base;
	}
	return (ret);
}

char	*ft_ltoa_10(int64_t nbr)
{
	char	*tmp;
	char	*ret;
	char	l[2];

	if (nbr >= 0)
		return (ft_ultoa_base(nbr, 10));
	l[0] = ((nbr % 10) * -1) + '0';
	l[1] = '\0';
	nbr = (nbr / 10) * -1;
	if (nbr)
	{
		tmp = ft_ultoa_base(nbr, 10);
		ret = malloc(ft_strlen(tmp) + 3);
		ft_strcpy(ret, "-");
		ft_strcat(ret, tmp);
		free(tmp);
	}
	else
	{
		ret = malloc(3);
		ft_strcpy(ret, "-");
	}
	ft_strcat(ret, l);
	return (ret);
}

void	ftpf_resetpart(void)
{
	g_part.width = 0;
	g_part.prec = 0;
	g_part.arg = 0;
	g_part.flags = 0;
	g_part.p = 0;
	g_part.length = 0;
}

int		ftpf_parse(char **parts, const char *format, va_list ap)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i > 0)
				*parts++ = ftpf_gspart(&format, &len, &i);
			format++;
			*parts++ = ftpf_getstr(&format, &len, ap);
			ftpf_resetpart();
		}
		if (format[i] && format[i] != '%')
			++i;
	}
	if (i)
		*parts++ = ftpf_gspart(&format, &len, &i);
	*parts = 0;
	return (len);
}

char	*ftpf_gspart(const char **format, int *len, int *plen)
{
	char *str;

	str = ft_strsub(*format, 0, *plen);
	*len += *plen;
	(*format) += *plen;
	*plen = 0;
	return (str);
}

void	ftpf_converter(char c)
{
	if (c == 'D' || c == 'O' || c == 'U' || c == 'C' || c == 'S')
	{
		g_part.length |= l;
		c += 32;
		g_part.type = c;
	}
	else
		g_part.type = c;
	if (g_part.type == 'i')
		g_part.type = 'd';
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		if (c == 'o')
			g_part.base = 8;
		else if (c == 'u')
			g_part.base = 10;
		else
		{
			if (c == 'X')
				g_part.flags |= X;
			g_part.base = 16;
		}
		g_part.type = 'u';
	}
}

char	*ftpf_noarg(char c, int *len)
{
	char	*ret;

	ret = malloc(2);
	if (!c)
	{
		ret[0] = '\0';
		return (ret);
	}
	ret[0] = c;
	ret[1] = '\0';
	*len += 1;
	if (g_part.width > 1)
		return (ftpf_pad(ret, len, 1));
	return (ret);
}

char	*ftpf_chars(int *len, va_list ap)
{
	char	*ret;

	ret = malloc(5);
	ret[0] = (char)va_arg(ap, int);
	ret[1] = '\0';
	*len += 1;
	if (g_part.width > 1)
		return (ftpf_pad(ret, len, 1));
	return (ret);
}

void	ft_strcatmulti(char *s1, char *s2, uint64_t times)
{
	while (times)
	{
		ft_strcat(s1, s2);
		--times;
	}
}

void	ftpf_signedmods(char **str, int *tlen, size_t len)
{
	char	*tmp;

	if (len != ft_strlen(*str))
	{
		tmp = ft_strnew(len);
		if (!(g_part.flags & (NEG | ZER)) && g_part.width)
			ft_strcatmulti(tmp, " ", g_part.width);
		if (**str == '-')
			ft_strcat(tmp, "-");
		else if (g_part.flags & (PLS | SPC))
			ft_strcat(tmp, (g_part.flags & PLS) ? "+" : " ");
		if ((g_part.flags & ZER) && !(g_part.flags & NEG) && g_part.width)
			ft_strcatmulti(tmp, (g_part.flags & ZER) ? "0" : " ", g_part.width);
		if (g_part.prec)
			ft_strcatmulti(tmp, "0", g_part.prec);
		ft_strcat(tmp, (**str == '-') ? (*str) + 1 : *str);
		if ((g_part.flags & NEG) && g_part.width)
			ft_strcatmulti(tmp, " ", g_part.width);
		free(*str);
		*str = tmp;
	}
	*tlen += len;
}

char	*ftpf_signed(int *len, va_list ap)
{
	char	*ret;
	size_t	slen;

	if (g_part.length & (l | ll | j | z))
		ret = ft_ltoa_10(va_arg(ap, long));
	else if (g_part.length & h)
		ret = ft_ltoa_10((short)va_arg(ap, int));
	else if (g_part.length & hh)
		ret = ft_ltoa_10((char)va_arg(ap, int));
	else
		ret = ft_ltoa_10(va_arg(ap, int));
	if (g_part.p && *ret == '0')
		*ret = '\0';
	if ((g_part.p && (g_part.flags & ZER)) || (g_part.flags & NEG))
		g_part.flags ^= ZER;
	if ((g_part.flags & (PLS | SPC)) == (PLS | SPC))
		g_part.flags ^= SPC;
	slen = (*ret == '-') ? ft_strlen(ret) - 1 : ft_strlen(ret);
	g_part.prec -= (g_part.prec > slen) ? slen : g_part.prec;
	slen += (*ret == '-') ? g_part.prec + 1 : g_part.prec;
	slen += ((g_part.flags & (PLS | SPC)) && *ret != '-') ? 1 : 0;
	g_part.width -= (g_part.width > slen) ? slen : g_part.width;
	slen += g_part.width;
	ftpf_signedmods(&ret, len, slen);
	return (ret);
}

char	*ftpf_pointer(int *len, va_list ap)
{
	char	*ret;
	char	*tmp;
	size_t	slen;

	ret = ft_ultoa_base(va_arg(ap, uint64_t), 16);
	if (*ret == '0' && g_part.p)
		*ret = '\0';
	slen = ft_strlen(ret);
	g_part.prec -= (g_part.prec > slen) ? slen : g_part.prec;
	slen += g_part.prec + 2;
	g_part.width -= (g_part.width > slen) ? slen : g_part.width;
	slen += g_part.width;
	tmp = ft_strnew(slen);
	if (!(g_part.flags & NEG) && g_part.width)
		ft_strcatmulti(tmp, " ", g_part.width);
	ft_strcat(tmp, "0x");
	ft_strcatmulti(tmp, "0", g_part.prec);
	ft_strcat(tmp, ret);
	if ((g_part.flags & NEG) && g_part.width)
		ft_strcatmulti(tmp, " ", g_part.width);
	free(ret);
	*len += slen;
	return (tmp);
}

void	ftpf_unsignedmods(char **str, int *tlen, size_t len)
{
	char	*tmp;

	if (**str == '0' && (g_part.p || g_part.flags & ALT))
	{
		**str = '\0';
		--len;
	}
	if (g_part.flags & ALT)
	{
		if (g_part.base == 8)
			++len;
		else if (g_part.base == 16)
			len += 2;
	}
	g_part.prec -= (g_part.prec > len) ? len : g_part.prec;
	len += g_part.prec;
	g_part.width -= (g_part.width > len) ? len : g_part.width;
	len += g_part.width;
	tmp = ft_strnew(len);
	if (!(g_part.flags & (NEG | ZER)) && g_part.width)
			ft_strcatmulti(tmp, " ", g_part.width);
	if (g_part.flags & ALT)
	{
		if (g_part.base == 8)
			ft_strcat(tmp, "0");
		else if (g_part.base == 16)
			ft_strcat(tmp, "0x");
	}
	if ((g_part.flags & ZER) && !(g_part.flags & NEG) && g_part.width)
		ft_strcatmulti(tmp, "0", g_part.width);
	if (g_part.prec)
		ft_strcatmulti(tmp, "0", g_part.prec);
	ft_strcat(tmp, *str);
	if ((g_part.flags & NEG) && g_part.width)
		ft_strcatmulti(tmp, (g_part.flags & ZER) ? "0" : " ", g_part.width);
	if (g_part.flags & X)
		ft_strupper(tmp);
	free(*str);
	*str = tmp;
	*tlen += len;
}

char	*ftpf_unsigned(int *len, va_list ap)
{
	char	*ret;
	size_t	slen;

	if (g_part.length & (l | ll | j | z))
		ret = ft_ultoa_base(va_arg(ap, uint64_t), g_part.base);
	else if (g_part.length & h)
		ret = ft_ultoa_base((uint16_t)va_arg(ap, uint32_t), g_part.base);
	else if (g_part.length & hh)
		ret = ft_ultoa_base((uint8_t)va_arg(ap, uint32_t), g_part.base);
	else
		ret = ft_ultoa_base(va_arg(ap, uint32_t), g_part.base);
	slen = ft_strlen(ret);
	if ((g_part.flags & ZER) && ((g_part.flags & NEG) || g_part.p))
		g_part.flags ^= ZER;
	if ((g_part.flags & ALT) && *ret == '0' && g_part.base != 8)
		g_part.flags ^= ALT;
	ftpf_unsignedmods(&ret, len, slen);
	return (ret);
}

t_parse	g_ftpffuncs[5] = {&ftpf_string, &ftpf_chars, &ftpf_signed,
						&ftpf_pointer, &ftpf_unsigned};

char	*ftpf_getstr(const char **format, int *len, va_list ap)
{
	static char	*types = "scdpu";
	uint8_t		i;

	i = 0;
	while (**format)
	{
		if (!ftpf_checkflags(format))
			if (!ftpf_checkprecision(format, ap))
				if (!ftpf_checknums(format, ap))
					if (!ftpf_checklength(format))
						break ;
	}
	ftpf_converter(**format);
	while (types[i] && types[i] != g_part.type)
		i++;
	if (**format)
		++(*format);
	if (types[i])
		return (g_ftpffuncs[i](len, ap));
	else
		return (ftpf_noarg(g_part.type, len));
}

//TODO: This might only really be for strings??

char	*ftpf_pad(char *str, int *len, size_t strl)
{
	char	*tmp;
	char	*thold;
	char	*shold;
	char	pad;

	pad = (g_part.flags & ZER && !(g_part.flags & NEG)) ? '0' : ' ';
	shold = str;
	tmp = malloc(g_part.width + 1);
	thold = tmp;
	g_part.width -= strl;
	*len += g_part.width;
	if (g_part.flags & NEG)
		while (*str)
			*tmp++ = *str++;
	while (g_part.width)
	{
		*tmp++ = pad;
		--g_part.width;
	}
	if (!(g_part.flags & NEG))
		while (*str)
			*tmp++ = *str++;
	*tmp = '\0';
	free(shold);
	return (thold);
}
