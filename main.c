/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:20:27 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/06 16:49:49 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#define SELF 1
#define	REAL 2
void	ft_printf_wstringtests(int i)
{
	wchar_t *str = L"ᆀǑǒǛڕiۂᅿᆀᆁ";
	char	*fmt = "%.3ls\n";

	if (i & SELF)
		ft_printf(fmt, str);
	if (i & REAL)
		printf(fmt, str);
}

int		main(void)
{
	setlocale(LC_ALL, "");
	ft_printf_wstringtests(3);
}
