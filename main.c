/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:00:17 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/13 01:37:37 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <locale.h>
#include <stdio.h>
#include <limits.h>
#include <libft.h>
#include <inttypes.h>
#include <strings.h>

int		ft_vasprintf(char **ret, const char *format, va_list ap);
int		ft_asprintf(char **ret, const char *format, ...);
int		ft_printf(const char *format, ...);

void	test(char *format, ...)
{
	char	*ret1;
	char	*ret2;
	int		iret1;
	int		iret2;
	int		errors;
	va_list	ap;
	va_list cap;

	errors = 0;
	va_start(ap, format);
	va_copy(cap, ap);
	iret1 = ft_vasprintf(&ret1, format, ap);
	iret2 = vasprintf(&ret2, format, cap);
	if (strcmp(ret1, ret2))
	{
		ft_putendl("");
		ft_putstr(format);
		ft_putstr(ret1);
		ft_putstr(ret2);
		errors += 1;
	}
	if (iret1 - iret2)
	{
		ft_putstr("Got: ");
		ft_putnbr(iret1);
		ft_putstr(" Expected: ");
		ft_putnbr(iret2);
		ft_putendl("");
		errors += 1;
	}
	if (!errors)
		ft_putchar('.');
	else
		ft_putendl("------------");
	free(ret1);
	free(ret2);
}

int	main(void)
{
	char c = 'a';
	test("%s\n", "Hello");
	test("%s %s\n", "Hello", "World");
	test("%2$s %1$s\n", "Hello", "World");
	test("%.1s\n", "Hello");
	test("%.*s\n", 2, "Hello");
	test("%.*10s\n", 2, "Hello");
	test("%-.*10s\n", 2, "Hello");
	test("%0-.*10s\n", 2, "Hello");
	test("%0.*10s\n", 2, "Hello");
	test("%%\n");
	test("%.%\n");
	test("%10.%\n");
	test("%1.%\n");
	test("%2.%\n");
	test("%2.3%\n");
	test("%-10.%\n");
	test("%-10.r\n");
	test("%-10.");
	test("%-10.👩");
	test("%p\n", &c);
	test("%p\n", 0);
	test("%.3p\n", &c);
	test("%20.3p\n", &c);
	test("%020.3p\n", &c);
	test("%-020.3p\n", &c);
	test("%s %p\n", "Hello", &c);
	test("");
	test("%d\n", 10);
	test("%d\n", -10);
	test("%hhd\n", 'j');
	test("%hho\n", 'j');
	test("%hhx\n", 'j');
	test("%hhX\n", 'j');
	test("%llX\n", (intmax_t)~0);
	test("%jX\n", (intmax_t)~0);
	test("%d\n", (int)~0);
	test("%#X\n", 16);
	test("%#x\n", 16);
	test("%#o\n", 16);
	test("%#O\n", 16);
	test("%#d\n", 16);
	test("%020.3x\n", 1231);
	test("%-020.3x\n", 1231);
	test("%-020x\n", 1231);
	test("%d\n", INT_MIN);
	test("%d\n", INT_MAX);
	test("%u\n", UINT_MAX);
	test("%zd\n", UINT_MAX);
	test("%ld\n", LONG_MIN);
	test("%ld\n", LONG_MAX);
	test("%d\n", LONG_MAX);
	test("%hhd\n", LONG_MAX);
	test("%lu\n", ULONG_MAX);
	test("%jd\n", INTMAX_MAX);
	test("%ju\n", UINTMAX_MAX);
	setlocale(LC_ALL, "");
	test("%-10.👩");
	test("%-10.👩d");
	test("%ls\n", L"Hello");
	test("%ls\n", L"👩🏽‍🚒");
	test("%.3ls\n", L"👩🏽‍🚒");
	test("%.5ls\n", L"👩🏽‍🚒");
	test("% -010.5ls\n", L"👩🏽‍🚒");
	test("% -010.5S\n", L"👩🏽‍🚒");
}
