/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:50:14 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/29 17:22:27 by bmontoya         ###   ########.fr       */
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
	static const char	*dlength = "hl";
	static const char	*length = "jzL";
	int					i;

	i = 0;
	while (dlength[i] && dlength[i] != **format)
		i++;
	if (dlength[i])
	{
		(*format)++;
		if (**format == dlength[i])
		{
			part->length = (i) ? ll : hh;
			(*format)++;
		}
		else
			part->length = (i) ? l : h;
		return (1);
	}
	i = 0;
	while (length[i] && length[i] != **format)
		i++;
	if (length[i])
	{
		(*format)++;
		part->length = i + 4;
		return (1);
	}
	return (0);
}

int	check_numbers(const char **format, t_part *part)
{
	unsigned long long int result;

	result = 0;
	while (ft_isdigit(**format))
	{
		result = (result * 10) + (**format - '0');
		(*format)++;
	}
	if (result)
	{
		if (**format == '$')
			part->arg = result;
		else if (part->prec)
			part->pmin = result;
		else
			part->width = result;
		return (1);
	}
	return (0);
}
