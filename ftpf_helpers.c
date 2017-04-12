/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:01:20 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/11 20:07:18 by bmontoya         ###   ########.fr       */
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
	if	(!nbr)
		ret[0] = '0';
	while (nbr)
	{
		ret[length--] = "0123456789abcdef"[nbr % base];
		nbr /= base;
	}
	return (ret);
}

char	*ftpf_pointer(int *len, va_list ap)
{
	char		*tmp;
	char		*ret;
	size_t		slen;

	tmp = ft_ultoa_base(va_arg(ap, uint64_t), 16);
	slen = ft_strlen(tmp) + 2;
	*len += slen;
	ret = malloc(slen + 1);
	ft_strcpy(ret, "0x");
	ft_strcat(ret, tmp);
	free(tmp);
	if (g_part.flags & ZER)
		g_part.flags ^= ZER;
	if (g_part.width > slen)
		return(ftpf_pad(ret, len, slen));
	else
		return (ret);
}

t_parse	g_func[3] = {&ftpf_string, &ftpf_string, &ftpf_pointer};

char	*ftpf_getstr(const char **format, int *len, va_list ap)
{
	static char	*types = "sSp";
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
	//TODO: Make a converter function
	if (**format == 'C' || **format == 'S')
		g_part.length |= l;
	while (types[i] && types[i] != **format)
		i++;
	++(*format);
	if (types[i])
		return(g_func[i](len, ap));
	else
		return(0);
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
