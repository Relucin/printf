/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_makeparts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 23:35:39 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/02 23:58:35 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftpf_makeparts.h"

t_list	*make_part(const char **format, va_list ask, t_diarr *arr)
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
					if (!check_numbers(format, info, arr))
							break;
	}
	info->type = **format;
	(*format)++;
	((t_gpart*)node->content)->data = info;
	((t_gpart*)node->content)->prec = 0;
	return (node);
}

void	make_partstr(const char **format, int *i, t_list **tokens)
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
