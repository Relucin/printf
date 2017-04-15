/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 03:29:50 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/13 15:04:32 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

// char	*ftpf_intflags(char *str, int *len, size_t *slen)
// {
// 	char	*ret;
//
// 	if (g_part.flags & ALT)
// 	{
// 		ret = ftpf_alt(str, len, slen);
// 		return (ret);
// 	}
// 	else if (g_part.flags & (PLS | SPC) && g_part.base == 10
// 			&& *str != '-' && !(g_part.length & z))
// 	{
// 		ret = malloc(*slen + 2);
// 		*slen += 1;
// 		*len += 1;
// 		if (g_part.flags & PLS)
// 			ft_strcpy(ret, "+");
// 		else
// 			ft_strcpy(ret, " ");
// 		ft_strcat(ret, str);
// 		free(str);
// 		return (ret);
// 	}
// 	return (str);
// }

// char	*ftpf_intprec(char *str, int *len, size_t *slen)
// {
// 	char	*ret;
//
// 	if (*str == '0' && !g_part.prec)
// 	{
// 		free(str);
// 		str = ft_strnew(1);
// 		if (g_part.flags & ALT && g_part.base == 16 && g_part.type != 'p')
// 			g_part.flags ^= ALT;
// 		*len -= 1;
// 		*slen -= 1;
// 	}
// 	else if (g_part.prec > *slen)
// 	{
// 		if (*str == '-' || *str == '+')
// 		{
// 			ret = malloc(++g_part.prec + 1);
// 			ft_strcpy(ret, (*str == '-') ? "-" : "+");
// 		}
// 		else
// 		{
// 			ret = malloc(g_part.prec + 1);
// 			ret[0] = '\0';
// 		}
// 		g_part.prec -= *slen;
// 		*len += g_part.prec;
// 		*slen += g_part.prec;
// 		while (g_part.prec)
// 		{
// 			ft_strcat(ret, "0");
// 			g_part.prec -= 1;
// 		}
// 		ft_strcat(ret, (*str == '-' || *str == '+') ? str + 1 : str);
// 		free(str);
// 		return (ret);
// 	}
// 	return (str);
// }

// char	*ftpf_intpad(char *str, int *len, size_t slen)
// {
// 	char	*tmp;
// 	char	*thold;
// 	char	*shold;
// 	char	pad;
//
// 	pad = (g_part.flags & ZER && !(g_part.flags & NEG)) ? '0' : ' ';
// 	shold = str;
// 	tmp = malloc(g_part.width + 1);
// 	thold = tmp;
// 	g_part.width -= slen;
// 	*len += g_part.width;
// 	if ((*str == '-' || *str == '+') && (g_part.flags & ZER))
// 		ft_strcpy(tmp++, (*str++ == '-') ? "-" : "+");
// 	if (g_part.flags & NEG)
// 		while (*str)
// 			*tmp++ = *str++;
// 	while (g_part.width)
// 	{
// 		*tmp++ = pad;
// 		--g_part.width;
// 	}
// 	if (!(g_part.flags & NEG))
// 		while (*str)
// 			*tmp++ = *str++;
// 	*tmp = '\0';
// 	free(shold);
// 	return (thold);
// }
//
// char	*ftpf_ints(int *len, va_list ap)
// {
// 	char	*ret;
// 	size_t	slen;
//
// 	if (g_part.base == 10 && !(g_part.length & z))
// 	{
// 		if (g_part.length & (l | ll | j))
// 			ret = ft_ltoa_10(va_arg(ap, int64_t));
// 		else if (g_part.length & hh)
// 			ret = ft_ltoa_10((char)va_arg(ap, int32_t));
// 		else if (g_part.length & h)
// 			ret = ft_ltoa_10((short)va_arg(ap, int32_t));
// 		else
// 			ret = ft_ltoa_10(va_arg(ap, int32_t));
// 	}
// 	else
// 	{
// 		if (g_part.length & (l | ll | j)|| g_part.type == 'p')
// 			ret = ft_ultoa_base(va_arg(ap, uint64_t), g_part.base);
// 		else if (g_part.length & hh)
// 			ret = ft_ultoa_base((uint8_t)va_arg(ap, uint32_t), g_part.base);
// 		else if (g_part.length & h)
// 			ret = ft_ultoa_base((uint16_t)va_arg(ap, uint32_t), g_part.base);
// 		else
// 			ret = ft_ultoa_base(va_arg(ap, uint32_t), g_part.base);
// 	}
// 	slen = ft_strlen(ret);
// 	*len += slen;
// 	if (g_part.p)
// 		ret = ftpf_intprec(ret, len, &slen);
// 	ret = ftpf_intflags(ret, len, &slen);
// 	if (g_part.flags & X)
// 		ft_strupper(ret);
// 	if (g_part.flags & ZER && ((g_part.flags & ALT)
// 		|| (g_part.p && g_part.type != 'p')))
// 		g_part.flags ^= ZER;
// 	if (g_part.width > slen)
// 		return (ftpf_intpad(ret, len, slen));
// 	return (ret);
// }

char	*ftpf_alt(char *str, int *len, size_t *slen)
{
	char	*ret;
	uint8_t	alen;

	if ((g_part.base == 8 || g_part.base == 16)
		&& (*str != '0' || g_part.type == 'p'))
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
