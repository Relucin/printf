/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_dchararray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:22:12 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/05 16:33:44 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ftpf_darrays.h"

t_dcarr	*ftpf_dcarrnew(unsigned int size)
{
	t_dcarr		*new;

	new = malloc(sizeof(t_dcarr));
	new->size = (size < 3) ? size : 10;
	new->len = 0;
	new->array = malloc(sizeof(char) * new->size);
	return (new);
}

/*
** TODO: Actually verify that the resizing is working correctly
*/

void	ftpf_dcarradd(t_dcarr *arr, char val)
{
	char	*tarr;

	if (arr->len == arr->size)
	{
		arr->size += (arr->size) / 2;
		tarr = malloc(sizeof(int) * arr->size);
		ft_memcpy(tarr, arr->array, arr->size * sizeof(char));
		free(arr->array);
		arr->array = tarr;
	}
	arr->array[(arr->len)++] = val;
}

/*
** TODO: Make this for a generic type and place in libft
*/

void	ftpf_dcarrdel(t_dcarr **arr)
{
	free((*arr)->array);
	free(*arr);
	*arr = 0;
}
