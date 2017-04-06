/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/06 16:53:27 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_makeparts.h"
#include "ft_printf.h"

t_parse			g_func[1] = {&ftfp_string};

void	print_tokens(t_part *token, t_darr *arr, va_list ap, int *n)
{
	va_list			cpy;
	static char		*types = "s";
	int				loc;

	va_copy(cpy, ap);
	loc = arr->array[token->arg - 1];
	while (loc)
	{
		(void)va_arg(cpy, void*);
		loc--;
	}
	while (types[loc] && token->type != types[loc])
		loc++;
	if (types[loc])
	{
		(void)g_func[loc](token, cpy, n);
	}
	else
	{
		ft_putchar(token->type);
	}
	va_end(cpy);
}

/*
**TODO: Modify this to have a function print out the proper thing
*/

int		print_list(t_list *tokens, t_darr *arr, va_list ap)
{
	t_gpart		*tmp;
	int			n;

	n = 0;
	while (tokens)
	{
		tmp = (t_gpart*)tokens->content;
		if (tmp->prec)
		{
			ft_putstr((char*)tmp->data);
		}
		else
		{
			print_tokens(tmp->data, arr, ap, &n);
		}
		tokens = tokens->next;
	}
	return (n);
}

/*
** TODO: Make a global max_arg that fills the dintarray if not enough args
*/

int		ft_vprintf(const char *format, va_list ap)
{
	va_list	ask;
	t_darr	*dintarray;
	t_list	*tokens;
	int		i;
	int		arg;

	va_copy(ask, ap);
	i = 0;
	tokens = 0;
	arg = 1;
	dintarray = ft_darrnew(10, sizeof(int));
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i > 0)
				make_partstr(&format, &i, &tokens);
			format++;
			ft_lstaddback(&tokens, make_part(&format, ask, dintarray, &arg));
		}
		if (format[i])
			i++;
	}
	va_end(ask);
	if (i > 0)
		make_partstr(&format, &i, &tokens);
	return (print_list(tokens, dintarray, ap));
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		i;

	va_start(ap, format);
	i = ft_vprintf(format, ap);
	va_end(ap);
	return (i);
}
