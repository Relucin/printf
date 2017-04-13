/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:01:20 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/13 01:23:07 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

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
		if (format[i])
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

void	ftpf_converter(char c)
{
	if (c == 'D' || c == 'O' || c == 'U' || c == 'C' || c == 'S')
	{
		g_part.length |= l;
		c += 32;
		g_part.type = c;
	}
	if (c == 'p')
	{
		g_part.flags |= ALT;
		c = 'x';
	}
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
	{
		if (c == 'd' || c == 'i' || c == 'u')
		{
			if (c == 'u')
				g_part.length |= z;
			g_part.base = 10;
		}
		else if (c == 'o')
			g_part.base = 8;
		else
		{
			if (c == 'X')
				g_part.flags |= X;
			g_part.base = 16;
		}
		g_part.type = 'i';
	}
	else
		g_part.type = c;
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

void	ft_strupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

char	*ftpf_alt(char *str, int *len, size_t *slen)
{
	char	*ret;
	uint8_t	alen;

	if (g_part.base == 8 || g_part.base == 16)
	{
		alen = g_part.base / 8;
		*len += alen;
		*slen += alen;
		ret = malloc(ft_strlen(str) + alen + 1);
		if (alen == 1)
			ft_strcpy(ret, "0");
		else
			ft_strcpy(ret, "0x");
		ft_strcat(ret, str);
		free(str);
		return (ret);
	}
	return (str);
}

char	*ftpf_ints(int *len, va_list ap)
{
	char	*ret;
	size_t	slen;

	if (g_part.base == 10 && !(g_part.length & z))
	{
		if (g_part.length & z)
			ft_putendl("?");
		if (g_part.length & (l | ll | j))
			ret = ft_ltoa_10(va_arg(ap, int64_t));
		else
			ret = ft_ltoa_10(va_arg(ap, int32_t));
	}
	else
		ret = ft_ultoa_base(va_arg(ap, uint64_t), g_part.base);
	slen = ft_strlen(ret);
	*len += slen;
	if (g_part.flags & ALT)
		ret = ftpf_alt(ret, len, &slen);
	if (g_part.flags & X)
		ft_strupper(ret);
	if (g_part.flags & ZER)
		g_part.flags ^= ZER;
	if (g_part.width > slen)
		return (ftpf_pad(ret, len, slen));
	return (ret);
}

t_parse	g_func[2] = {&ftpf_string, &ftpf_ints};

char	*ftpf_getstr(const char **format, int *len, va_list ap)
{
	static char	*types = "si";
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
		return (g_func[i](len, ap));
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
	*len = g_part.width;
	g_part.width -= strl;
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
