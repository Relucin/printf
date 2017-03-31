/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/30 22:29:13 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_checks.h"

#define CHECKS 4
#include <stdio.h>
//TODO: Create a function to build s_parts??

/*t_list	*create_tokens(const char *format)
{
	t_list					*tokns = 0;
	t_part					*part;
	int							i;

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
}*/

static void	make_part(const char **format, t_list **tokens, va_list ask)
{
	t_gpart part;
	t_part	*info;
	t_list	*node;

	part.prec = 0;
	node = ft_lstnew(&part, sizeof(&part));
	info = malloc(sizeof(t_part));
	info->flags = 0;
	info->prec = 0;
	info->arg = 0;
	info->pmin = 0;
	info->length = 0;
	while (1)
	{
		if (!check_flags(format, info))
			if (!check_precision(format, info))
				if (!check_length(format, info))
					if (!check_numbers(format, info))
						{
							info->type = **format;
							break;
						}
	}
	(*format)++;
	((t_gpart*)node->content)->data = info;
	ft_lstaddback(tokens, node);
}
static void	make_partstr(const char **format, int *i, t_list **tokens)
{
	t_list *node;
	t_gpart partstr;
	t_gpart *tpart;

	node = ft_lstnew(&partstr,sizeof(&partstr));
	tpart = (t_gpart*)node->content;
	tpart->prec = 1;
	tpart->data = ft_strsub(*format, 0, *i);
	*format += *i;
	*i = 0;
	ft_lstaddback(tokens, node);
}

static void	print_list(t_list *tokens)
{
	t_gpart *tmp;
	t_part	*tmp2;
	while (tokens)
	{
		tmp = (t_gpart*)tokens->content;
		if (tmp->prec)
			ft_putstr((char*)tmp->data);
		else
		{
			tmp2 = (t_part*)tmp->data;
			ft_putchar(tmp2->type);
		}
		tokens = tokens->next;
	}
}

int		ft_vprintf(const char *format, va_list ap)
{
	va_list	ask;
	//Have dynamic int array to properly get data from ap
	t_list	*tokens;
	int			i;

	va_copy(ask,ap);
	i = 0;
	tokens = 0;
	//Make darray
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i > 0)
				make_partstr(&format, &i, &tokens);
			format++;
			make_part(&format, &tokens, ask);
		}
		i++;
	}
	va_end(ask);
	if (i > 0)
		make_partstr(&format, &i, &tokens);
	print_list(tokens);
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
