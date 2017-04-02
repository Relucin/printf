/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_makeparts.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 00:56:56 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/02 01:31:40 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_MAKEPARTS_H
# define FTPF_MAKEPARTS_H
# include "ft_printf.h"
# include "ftpf_checks.h"
t_list	*make_part(const char **format, va_list ask, t_diarr *arr);
void	make_partstr(const char **format, int *i, t_list **tokens);
#endif
