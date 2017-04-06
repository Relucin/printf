/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:50:14 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/04 14:53:24 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flags(const char **format, t_part *part)
{
	static const char	*flags = "#0- +";
	int					i;

	i = 0;
	while (flags[i] && flags[i] != **format)
		i++;
	if (flags[i])
	{
		part->flags |= (1 << i);
		(*format)++;
		return (1);
	}
	return (0);
}

int		check_precision(const char **format, t_part *part)
{
	static const char	precision = '.';

	if (**format == precision)
	{
		part->prec = 1;
		part->pmin = 0;
		(*format)++;
		return (1);
	}
	return (0);
}

/*
** TODO: Do comparisions when figure out how to set t_part
*/

int		check_length(const char **format, t_part *part)
{
	static const char		*dlength = "hl";
	static const char		*length = "jzL";
	int						i;

	i = 0;
	while (dlength[i] && dlength[i] != **format)
		i++;
	if (dlength[i])
	{
		(*format)++;
		if (**format == dlength[i])
		{
			part->length |= (i) ? ll : hh;
			(*format)++;
		}
		else
			part->length |= (i) ? l : h;
		return (1);
	}
	i = 0;
	while (length[i] && length[i] != **format)
		i++;
	if (length[i])
	{
		(*format)++;
		part->length |= ((1 << 3) << (i + 1));
		return (1);
	}
	return (0);
}

int		check_numbers(const char **f, t_part *part, va_list ask, t_darr *arr)
{
	unsigned long long int result;

	result = 0;
	while (ft_isdigit(**f))
	{
		result = (result * 10) + (**f - '0');
		(*f)++;
	}
	if (!result && **f == '*')
	{
		(*f)++;
		if (**f == '$')
		{
			(*f)++;
			return (1);
		}
		arr->array[arr->len - 1] += 1;
		result = va_arg(ask, int);
	}
	if (result)
	{
		if (**f == '$')
		{
			part->arg = result;
			(*f)++;
		}
		else if (part->prec)
			part->pmin = result;
		else
			part->width = result;
		return (1);
	}
	return (0);
}
