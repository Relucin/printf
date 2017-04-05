/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 22:31:06 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/04 21:27:54 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
int	main(void)
{
	wchar_t c =  L'字';
	setlocale(LC_CTYPE, "");
	//ft_printf("Hello %3$s %1$s %2$s\n", "World", "Hello", "Test");
	//ft_printf("%s\n", "Hello");
	ft_printf("%ls\n", L"字a");
	printf("%ls\n", L"字");
	//printf("%d\n", printf("%lsa\n", L"Hello"));
	//printf("%d\n", printf("%lsa\n", L"Hello§"));
	//ft_printf("%-10.10sa\n", "Hello");
	//printf("%-10.10sa\n", "Hello");
	//ft_printf("%.10sa\n", "Hello");
	//printf("%.10sa\n", "Hello");
	//ft_printf("%.3sa\n", 0);
	//printf("%.3sa\n", 0);
	//ft_printf("%-10sa\n", "Hello");
	//printf("%-10sa\n", "Hello");
}

/*
**	printf("Hello %3$s %1$s %2$s\n","World", "Hello", "Test");
**}
*/
