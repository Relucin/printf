/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:58:03 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/04 08:36:54 by bmontoya         ###   ########.fr       */
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
** Uses only - and 0
*/

void	ftfp_string(t_part *token, va_list ap, int *n)
{
	char	*str;
	char	spacing;

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
