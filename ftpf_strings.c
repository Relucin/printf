/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:58:03 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/06 16:47:49 by bmontoya         ###   ########.fr       */
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

void	ftfp_wstring2(char *ret, wchar_t str)
{
	int		i;

	i = 0;
	if (str < (1 << 7))
		ret[i++] = str;
	else
	{
		if (str < (1 << 11))
			ret[i++] = 0xC0 | (str >> 6);
		else
		{
			if (str < (1 << 16))
				ret[i++] = 0xE0 | (str >> 12);
			else
			{
				ret[i++] = 0xF0 | (str >> 18);
				ret[i++] = 0x80 | ((str >> 12) & 0x3F);
			}
			ret[i++] = 0x80 | ((str >> 6) & 0x3F);
		}
		ret[i++] = 0x80 | (str & 0x3F);
	}
	ret[i] = 0;
}

/*
** TODO: Free t_dcarr...
*/

char	*ftfp_wstring(va_list ap)
{
	wchar_t	*str;
	t_darr	*tmp;
	char	*ctmp;
	int		i;

	ctmp = malloc(5);
	tmp = ft_darrnew(30, sizeof(char));
	str = va_arg(ap, wchar_t*);
	while (*str)
	{
		ftfp_wstring2(ctmp, *str);
		i = 0;
		while (ctmp[i])
		{
			ft_darraddback(tmp, ctmp[i++]);
		}
		str++;
	}
	ft_darraddback(tmp, '\0');
	free(ctmp);
	ctmp = tmp->array;
	free(tmp);
	return (ctmp);
}

/*
** Uses only - and 0
*/

void	ftfp_string(t_part *token, va_list ap, int *n)
{
	char	*str;
	char	spacing;

	(void)n;
	if (token->length & l)
		str = ftfp_wstring(ap);
	else
		str = va_arg(ap, char*);
	spacing = (token->flags & ZER) ? '0' : ' ';
	str = (str) ? str : "(null)";
	token->pmin = (token->prec) ? token->pmin : ft_strlen(str);
	token->pmin = (token->pmin > ft_strlen(str)) ? ft_strlen(str) : token->pmin;
	if (token->width >= token->pmin)
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
