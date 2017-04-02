/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/02 01:28:46 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_makeparts.h"
#include "ft_printf.h"
//TODO: Pass in ap and darray to properly place values
static void	print_list(t_list *tokens, t_diarr *arr)
{
	t_gpart *tmp;
	t_part	*tmp2;
	int			n;

	n = 0;
	while (tokens)
	{
		tmp = (t_gpart*)tokens->content;
		if (tmp->prec)
			ft_putstr((char*)tmp->data);
		else
		{
			tmp2 = (t_part*)tmp->data;
			//TODO: Modify this to have a function print out the proper thing
			ft_putchar(tmp2->type);
		}
		tokens = tokens->next;
	}
}

int		ft_vprintf(const char *format, va_list ap)
{
	va_list	ask;
	t_diarr *dintarray;
	t_list	*tokens;
	int			i;

	va_copy(ask,ap);
	i = 0;
	tokens = 0;
	dintarray = ftpf_diarrnew(10);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i > 0)
				make_partstr(&format, &i, &tokens);
			format++;
			ft_lstaddback(&tokens, make_part(&format, ask, dintarray));
		}
		if (format[i])
			i++;
	}
	va_end(ask);
	if (i > 0)
		make_partstr(&format, &i, &tokens);
	print_list(tokens, dintarray);
	//Pass in ap,tokens, and dynamic ints to print each link in ll put in return
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int			i;

	va_start(ap, format);
	i = ft_vprintf(format, ap);
	va_end(ap);
	return (i);
}
