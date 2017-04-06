/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 21:41:08 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/06 15:02:43 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_darray.h"
#include "libft.h"

/*
** TODO: Change size to a bit field??
** 	cap: The number of elements the array should be init with
** size: The sizeof the elements of the array
*/

t_darr	*ft_darrnew(size_t cap, size_t size)
{
	t_darr	*new;

	new = malloc(sizeof(t_darr));
	new->array = malloc(cap * size);
	new->size = size;
	new->cap = cap;
	new->len = 0;
	return (new);
}

void	ft_darraddback(t_darr *arr, int64_t data)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (arr->cap == arr->len)
	{
		arr->cap += (arr->cap / 2);
		tmp = arr->array;
		arr->array = malloc(arr->cap * arr->size);
		ft_memcpy(arr->array, tmp, arr->len);
		free(tmp);
	}
	while (i < arr->size)
		arr->array[arr->len++] = (data >> (i++ * 8)) & (((1 << 8) - 1));
}

size_t	ft_darrlen(t_darr *arr)
{
	return (arr->len / arr->size);
}

int64_t	ft_dag(t_darr *arr, size_t index)
{
	return (*((int64_t*)(arr->array + (index * arr->size))));
}

void	ft_darrdel(t_darr **arr)
{
	free((*arr)->array);
	free(*arr);
	*arr = 0;
}
