/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_dintarray.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 00:49:00 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/02 00:51:45 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_DINTARRAY_H
# define FTPF_DINTARRAY_H
typedef struct	s_diarr
{
	int						*array;
	unsigned int	len;
	unsigned int	size;
}								t_diarr;

t_diarr					*ftpf_diarrnew(unsigned int size);
void						ftpf_diarradd(t_diarr *arr, int val);
void						ftpf_diarrdel(t_diarr **arr);
#endif
