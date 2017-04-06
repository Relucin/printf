/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_darrays.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 00:49:00 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/05 16:32:47 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_DARRAYS_H
# define FTPF_DARRAYS_H
typedef struct	s_diarr
{
	int				*array;
	unsigned int	len;
	unsigned int	size;
}					t_diarr;

typedef struct	s_dcarr
{
	char			*array;
	unsigned int	len;
	unsigned int	size;
}					t_dcarr;

t_diarr				*ftpf_diarrnew(unsigned int size);
void				ftpf_diarradd(t_diarr *arr, int val);
void				ftpf_diarrdel(t_diarr **arr);
t_dcarr				*ftpf_dcarrnew(unsigned int size);
void				ftpf_dcarradd(t_dcarr *arr, char val);
void				ftpf_dcarrdel(t_dcarr **arr);
#endif
