/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:58:03 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/04 21:38:13 by bmontoya         ###   ########.fr       */
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

void	ftfp_wstring(t_part *token, va_list ap, int *n)
{
	wchar_t	*str;
	char	tmp[5];
	char	*stmp;

	str = va_arg(ap, wchar_t*);
	while (*str)
	{
		stmp = (char*)str;
		if (*str < (1 << 7))
			ft_putchar((char)*str);
		else if (*str < (1 << 11))
		{
			ft_putendl("test1");
			ft_putchar((char)*str);
		}
		else if (*str < (1 << 16))
		{
			tmp[0] = 0x70 | (stmp[1] >> 4);
			tmp[1] = 0x20 | (stmp[0] >> 6) | (stmp[1] & 0xF);
			tmp[2] = 0x20 | (stmp[0] & 0x3F);
			tmp[3] = 0;
			//ft_putnbr(*str);
			ft_putnstr(tmp, 4);
		}
		else
		{
			ft_putendl("test3");
			ft_putchar((char)*str);
		}
		str++;
	}
}

/*
** Uses only - and 0
*/

void	ftfp_string(t_part *token, va_list ap, int *n)
{
	char	*str;
	char	spacing;

	if (token->length & l)
	{
		ftfp_wstring(token,ap, n);
		return ;
	}
	spacing = (token->flags & ZER) ? '0' : ' ';
	str = va_arg(ap, char*);
	str = (str) ? str : "(null)";
	token->pmin = (token->prec) ? token->pmin : ft_strlen(str);
	token->pmin = (token->pmin > ft_strlen(str)) ? ft_strlen(str) : token->pmin;
	if (token->width - token->pmin >= 0)
		token->width = token->width - token->pmin;
	else
		token->width = 0;
	if (token->flags & NEG)
	{
		ft_putnstr(str, token->pmin);
		print_padding(spacing, token->width);
	}
	else
	{
		print_padding(spacing, token->width);
		ft_putnstr(str, token->pmin);
	}
}
