/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 19:02:46 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/11 15:15:57 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_printf.h"

int	ft_countrep(const char *str, char c)
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
	char	**parts;
	char	**phold;
	int		args;
	int		len;

	ftpf_resetpart();
	args = ft_countrep(format, '%');
	parts = malloc(sizeof(*parts) * (args * 2 + 2));
	phold = parts;
	len = ftpf_parse(parts, format, ap);
	if(!(*ret = malloc(len + 1)))
		return (-1);
	while (*parts)
	{
		ft_strlcat(*ret, *parts, len + 1);
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
	ft_putstr(cret);
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
