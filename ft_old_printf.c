/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:57:39 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/21 14:37:04 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <stdarg.h>

void	ft_putsub(const char* str, int start, size_t len)
{
	str += start;
	write(1, str, len);
}

/*t_list	*make_tokens(const char* format)
{
	int		i;
	int		vi;
	t_list	*head = 0;
	char	*param = "0123456789*$";
	char	*flag = "-+ 0#";
	char	*types = "%diufFeEgGxXoscpaAn";
	char	*length = "hlLzjt";
	//No t?maybe

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i > 0)
			{
				ft_lstaddback(&head,ft_lstnew(ft_strsub(format, 0, i), i+1));
				format += i;
				i = 0;
			}
			while (1)
			{
				vi = 0;
				i++;
				while (param[vi] && format[i] != param[vi])
					vi++;
				if (param[vi])
					continue ;
				vi = 0;
				while (flag[vi] && format[i] != flag[vi])
					vi++;
				if (flag[vi])
					continue ;
				vi = 0;
				while (length[vi] && format[i] != length[vi])
					vi++;
				if (length[vi])
	printf("%lu\n",sizeof(ptrdiff_t));
					continue ;
				if (i > 1)
					i++;
				ft_lstaddback(&head, ft_lstnew(ft_strsub(format, 0, i+1), i+2));
				format+= i+1;
				i = 0;
				break;
			}
		}
		i++;
	}
	if (i > 0)
	{
		ft_lstaddback(&head,ft_lstnew(ft_strsub(format, 0, i), i+1));
		i = 0;
	}
	return (head);
}*/

/*t_list	*create_tokens(const char *format)
{
	char	*flags = "0-+ #";
	char	*precs = ".";
	char	*ldoul = "hl";
	char	*lengh = "Lzj";
	char	*nmbrs = "0123456789";
	t_list	*tokns = 0;
	int		i = 0;
	int		ic = 0;
	int		ai = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i)
			{
				ft_lstaddback(&tokns, ft_lstnew(ft_strsub(format, 0, i), i + 1));
				format += i;
				i = 0;
			}
			while (format[++i])
			{
				ai = 0;
				while ("0-+ #"[ai] && format[i] != "0-+ #"[ai])
					ai++;
				if ("0-+ #"[ai])
					continue ;
				if (format[i] == '.')
					continue ;
				ai = 0;
				while ("hl"[ai] && format[i] != "hl"[ai])
					ai++;
				if ("hl"[ai])
					continue ;
				ai = 0;
				while ("Lzj"[ai] && format[i] != "Lzj"[ai])
					ai++;
				if ("Lzj"[ai])
					continue ;
				while (format[i])
				{
					ai = 0;
					while ("0123456789"[ai] && format[i] != "0123456789"[ai])
						ai++;
					if (!"0123456789"[ai])
						break ;
					ic += 1;
					i++;
				}
				if (ic)
				{
					ic = 0;
					if (format[i] == '$')
						continue;
				}
				i++;
				ft_lstaddback(&tokns, ft_lstnew(ft_strsub(format, 0, i), i + 1));
				format += i + 1;
				i = 0;
				break;
			}
			continue ;
		}
		i++;
	}
	if (i)
		ft_lstaddback(&tokns, ft_lstnew(ft_strsub(format, 0, i), i + 1));
	return (tokns);
}*/
int		check_parameter(const char *format)
{
	char	*valid = "0123456789";
	int		move = 0;
	int		vi = 0;

	if (format[0] == '0')
		return (move);
	return (0);
}
t_list	*make_tokens(const char *format)
{
	return (0);
}

int		ft_printf(const char* format, ...)
{
	va_list ap;
	int		i;
	int 	subi;
	
	i = 0;
	subi = 0;
	va_start(ap, format);
	return (0);
}
#include <stddef.h>
int		main()
{
	/*tokens = make_tokens("%$desting%d this %sstring");
	while (tokens->next)
	{
		printf("%s\n",tokens->content);
		tokens = tokens->next;
	}
	printf("%s\n",tokens->content);*/
}
