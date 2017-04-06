/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 22:21:42 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/06 01:19:14 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DARRAY_H
# define FT_DARRAY_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# define FT_DARRGET(a, i) (a->size == 1) ? (char)ft_dag(a, i) : D2(a, i)
# define D2(a, i) (a->size == sizeof(short)) ? (short)ft_dag(a, i) : D3(a, i)
# define D3(a, i) (a->size == 4) ? (int)ft_dag(a, i) : D4(a, i)
# define D4(a, i) (a->size == 8) ? (long)ft_dag(a, i) : 0

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
