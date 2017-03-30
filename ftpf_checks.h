/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_checks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:46:55 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/29 16:59:14 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPF_CHECKS_H
# define FTPF_CHECKS_H
# include "ft_printf.h"

int		check_flags(const char **format, t_part *part);
int		check_precision(const char **format, t_part *part);
int		check_length(const char **format, t_part *part);
int   check_numbers(const char **format, t_part *part);
#endif
