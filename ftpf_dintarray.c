/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_dintarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 00:25:40 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/03 22:38:02 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_diarr	*ftpf_diarrnew(unsigned int size)
{
	t_diarr		*new;

	new = malloc(sizeof(t_diarr));
	new->size = (size < 3) ? size : 10;
	new->len = 0;
	new->array = malloc(sizeof(int) * new->size);
	return (new);
}

/*
** TODO: Actually verify that the resizing is working correctly
*/

void	ftpf_diarradd(t_diarr *arr, int val)
{
	int	*tarr;

	if (arr->len == arr->size)
	{
		arr->size += (arr->size) / 2;
		tarr = malloc(sizeof(int) * arr->size);
		ft_memcpy(tarr, arr->array, arr->size * sizeof(int));
		free(arr->array);
		arr->array = tarr;
	}
	arr->array[(arr->len)++] = val;
}

void	ftpf_diarrdel(t_diarr **arr)
{
	free((*arr)->array);
	free(*arr);
	*arr = 0;
}
