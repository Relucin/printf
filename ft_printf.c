/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/31 02:29:53 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_checks.h"

static void	make_part(const char **format, t_list **tokens, va_list ask)
{
	t_gpart part;
	t_part	*info;
	t_list	*node;

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
							break;
	}
	info->type = **format;
	(*format)++;
	((t_gpart*)node->content)->data = info;
	((t_gpart*)node->content)->prec = 0;
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

//TODO: Pass in ap and darray to properly place values
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
			//TODO: Modify this to have a function print out the proper thing
			ft_putchar(tmp2->type);
		}
		tokens = tokens->next;
	}
}

int		ft_vprintf(const char *format, va_list ap)
{
	va_list	ask;
	//TODO: Have dynamic int array to properly get data from ap
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
			//Pass in dintarray ??
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
