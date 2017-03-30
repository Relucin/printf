/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 02:59:44 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/30 03:04:26 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

typedef struct
{
	va_list **arr;
	size_t	len;
	size_t	size;
}					t_vaparray;

t_vaparray	**ftpt_arraynew()
{
	return (0);
}
