/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:21:42 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/06 14:56:58 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DARRAY_H
# define FT_DARRAY_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# define FT_DAGETINT(arr, i) (int)ft_dag(arr, i)

typedef struct	s_darr
{
	char		*array;
	size_t		size;
	size_t		len;
	size_t		cap;
}				t_darr;

t_darr			*ft_darrnew(size_t cap, size_t size);
void			ft_darraddback(t_darr *arr, int64_t data);
size_t			ft_darrlen(t_darr *arr);
int64_t			ft_dag(t_darr *arr, size_t index);
#endif
