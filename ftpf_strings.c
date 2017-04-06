/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:58:03 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/05 23:10:09 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int n)
{
	write(1, str, n);
}

void	print_padding(char p, int t)
{
	while (t)
	{
		write(1, &p, 1);
		t--;
	}
}

/*
** TODO: Free t_dcarr...
*/

char	*ftfp_wstring(t_part *token, va_list ap)
{
	wchar_t	*str;
	t_dcarr	*tmp;

	tmp = ftpf_dcarrnew(10);
	str = va_arg(ap, wchar_t*);
	while (*str)
	{
		if (*str < (1 << 7))
			ftpf_dcarradd(tmp, *str);
		else
		{
			if (*str < (1 << 11))
				ftpf_dcarradd(tmp, 0xC0 | ((*str >> 6)));
			else
			{
				if (*str < (1 << 16))
					ftpf_dcarradd(tmp, 0xE0 | (*str >> 12));
				else
				{
					ftpf_dcarradd(tmp, 0xF0 | (*str >> 18));
					ftpf_dcarradd(tmp, 0x80 | ((*str >> 12) & 0x3F));
				}
				ftpf_dcarradd(tmp, 0x80 | ((*str >> 6) & 0x3F));
			}
			ftpf_dcarradd(tmp, 0x80 | (*str & 0x3F));
		}
		str++;
	}
	return (tmp->array);
}

/*
** Uses only - and 0
*/

void	ftfp_string(t_part *token, va_list ap, int *n)
{
	char	*str;
	char	spacing;

	if (token->length & l)
		str = ftfp_wstring(token, ap);
	else
		str = va_arg(ap, char*);
	spacing = (token->flags & ZER) ? '0' : ' ';
	str = (str) ? str : "(null)";
	token->pmin = (token->prec) ? token->pmin : ft_strlen(str);
	token->pmin = (token->pmin > ft_strlen(str)) ? ft_strlen(str) : token->pmin;
	if (token->width - token->pmin >= 0)
		token->width = token->width - token->pmin;
	else
		token->width = 0;
	if (!(token->flags & NEG))
		print_padding(spacing, token->width);
	ft_putnstr(str, token->pmin);
	if (token->flags & NEG)
		print_padding(spacing, token->width);
	if (token->length & l)
		free(str);
}
