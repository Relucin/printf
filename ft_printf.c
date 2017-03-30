/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/30 00:32:46 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_checks.h"
#include <stdarg.h>

#define CHECKS 4
#include <stdio.h>
//TODO: Create a function to build s_parts
t_list	*create_tokens(const char *format)
{
	t_list					*tokns = 0;
	t_part					*part;
	int						i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i)
			{
				part = malloc(sizeof(t_part));
				part->str = ft_strsub(format, 0, i);
				ft_lstaddback(&tokns, ft_lstnew(part,sizeof(part)));
				format += i;
				i = 0;
			}
			format++; //Removes the %
			part = malloc(sizeof(t_part));
			part->prec = 0;
			part->str = ft_strdup("{}");
			while (1)
			{
				if (check_flags(&format, part))
					continue;
				if (check_length(&format, part))
					continue;
				if (check_precision(&format, part))
					continue;
				if (check_numbers(&format, part))
					continue;
				break;
			}
			ft_lstaddback(&tokns, ft_lstnew(part,sizeof(part)));
			//TODO: Something with the type
			//Push first va_list into some data structure
			format++; //Removes the type
		}
		else
			i++;
	}
	if (i)
	{
		part = malloc(sizeof(t_part));
		part->str = ft_strdup(format);
		ft_lstaddback(&tokns, ft_lstnew(part,sizeof(part)));
	}
	return (tokns);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_list *tokens;

	va_start(ap, format);
	tokens = create_tokens(format);
	while (tokens)
	{
		ft_putstr(((t_part*)tokens->content)->str);
		tokens = tokens->next;
	}
	va_end(ap);
	return (0);
}

#include <stdio.h>
int		main(void)
{
	 ft_printf("TEST %d Hello%dTesting%s World\n", 'c', NULL);
	// printf("Size of %*s is %lu\n", 13, "char",sizeof(char));
	// printf("Size of %*s is %lu\n", 13, "void",sizeof(void));
	// printf("Size of %*s is %lu\n", 13, "short",sizeof(short));
	// printf("Size of %*s is %lu\n", 13, "long",sizeof(long));
	// printf("Size of %*s is %lu\n", 13, "long long",sizeof(long long));
	// printf("Size of %*s is %lu\n", 13, "size_t",sizeof(size_t));
	// printf("Size of %*s is %lu\n", 13, "double",sizeof(double));
	// printf("Size of %*s is %lu\n", 13, "void*",sizeof(void*));
	// printf("Size of %*s is %lu\n", 13, "long double",sizeof(long double));
}
