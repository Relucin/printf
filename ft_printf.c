/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:02:46 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/18 17:31:22 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

int		ft_countrep(const char *str, char c)
{
	int count;

	//TODO: Move this to libft
	count = 0;
	while (*str)
	{
		if (*str == c)
			++count;
		++str;
	}
	return (count);
}

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_string	**parts;
	t_string	**phold;
	char		*tret;
	int			len;

	ftpf_resetpart();
	len = ft_countrep(format, '%');
	parts = malloc(sizeof(*parts) * (len * 2 + 2));
	phold = parts;
	len = ftpf_parse(parts, format, ap);
	if (!(tret = ft_strnew(len)))
		return (-1);
	*ret = tret;
	while (*parts)
	{
		ft_strncpy(tret, (*parts)->str, (*parts)->len);
		tret += (*parts)->len;
		free(*parts);
		parts++;
	}
	free(phold);
	return (len);
}

int		ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		iret;

	va_start(ap, format);
	iret = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (iret);
}

int		ft_vprintf(const char *format, va_list ap)
{
	char	*cret;
	int		iret;

	iret = ft_vasprintf(&cret, format, ap);
	write(1, cret, iret);
	free(cret);
	return (iret);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}
