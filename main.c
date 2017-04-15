/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 21:00:17 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/14 22:50:39 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <locale.h>
#include <stdio.h>
#include <limits.h>
#include <libft.h>
#include <inttypes.h>
#include <strings.h>
#include "ft_printf.h"

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
	iret2 = vasprintf(&ret2, format, cap);
	iret1 = ft_vasprintf(&ret1, format, ap);
	if (strcmp(ret1, ret2))
	{
		ft_putendl("");
		ft_putendl(format);
		ft_putendl(ret1);
		ft_putendl(ret2);
		errors += 1;
	}
	// else
	// {
	// 	ft_putendl("");
	// 	ft_putstr(format);
	// 	ft_putstr(ret1);
	// 	ft_putstr(ret2);
	// }
	if (iret1 - iret2)
	{
		if (!errors)
		{
			ft_putendl("");
			ft_putendl(format);
			ft_putendl(ret1);
			ft_putendl(ret2);
		}
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
	// test("%s", "Hello");
	// test("%s %s", "Hello", "World");
	// test("%2$s %1$s", "Hello", "World");
	// test("%.1s", "Hello");
	// test("%.*s", 2, "Hello");
	// test("%.*10s", 2, "Hello");
	// test("%-.*10s", 2, "Hello");
	// test("%0-.*10s", 2, "Hello");
	// test("%0.*10s", 2, "Hello");
	// test("%%");
	// test("%.%");
	// test("%10.%");
	// test("%1.%");
	// test("%2.%");
	// test("%2.3%");
	// test("%-10.%");
	// test("%-10.r");
	// test("%-10.");
	// test("%-10.👩");
	// test("%s %p", "Hello", &c);
	// test("");
	// test("%%%");
	// test("%%%%");
	// test("%s", 0);
	// test("%.4s", "42");
	//C
	ft_putendl("---C---");
	test("%03c", 0);
	test("{% c}", 0);
	test("{%3c}", 0);
	//U
	ft_putendl("\n---U---");
	test("%zu", ULLONG_MAX);
	test("%hlu", 4294967296);
	test("%hU", 4294967296);
	test("%hho", 'j');
	test("%hhx", 'j');
	test("%hhX", 'j');
	test("%llX", (intmax_t)~0);
	test("%jX", (intmax_t)~0);
	test("%#X", 16);
	test("%#8x", 16);
	test("%#x", 16);
	test("%#o", 16);
	test("%#o", 0);
	test("%#O", 16);
	test("%020.3x", 1231);
	test("%-020.3x", 1231);
	test("%-020x", 1231);
	test("%u", UINT_MAX);
	test("%lu", ULONG_MAX);
	test("%ju", UINTMAX_MAX);
	test("%.4o", 42);
	test("%+# jx", INTMAX_MAX);
	test("%# jx", INTMAX_MAX);
	test("%+#jx", INTMAX_MAX);
	test("%#jx", INTMAX_MAX);
	test("%x", -42);
	test("%x", 0);
	test("%#x", 0);
	test("%#.o, %#.0o", 0, 0);
	test("%#.x", 0);
	test("%#.1x", 0);
	test("%#.x", 1);
	test("%o", LONG_MAX);
	test("% o|%+o", 42, 42);
	test("%hhu", UCHAR_MAX + 42);
	test("%hhu", UCHAR_MAX);
	test("%hhu", 0);
	test("% u", 9999);
	test("%030x", 0xFFFF);
	test("%#08x", 42);
	//P
	ft_putendl("\n---P---");
	test("%p", &c);
	test("%p", 0);
	test("%.5p", 0);
	test("%.20p", &c);
	test("%20.3p", &c);
	test("%020.3p", &c);
	test("%-020.3p", &c);
	test("%.0p, %.p", 0, 0);
	test("%.p", &c);
	//D
	ft_putendl("\n---D---");
	test("%zi", LLONG_MIN);
	test("%5d", -42);
	test("%-5d", -42);
	test("%-5d", 42);
	test("%-10.5d", 42);
	test("%-+10.5d", 42);
	test("%.d", 0);
	test("%5.d", 0);
	test("%5.0d", 0);
	test("%5.d", 0);
	test("%d", 10);
	test("%+d", -10);
	test("%d", -10);
	test("%hhd", 'j');
	test("%d", (int)~0);
	test("%d", INT_MIN);
	test("%d", INT_MAX);
	test("%zd", UINT_MAX);
	test("%ld", LONG_MIN);
	test("%ld", LONG_MAX);
	test("%d", LONG_MAX);
	test("%hhd", LONG_MAX);
	test("%jd", INTMAX_MAX);
	test("{%010d}", 42);
	test("%#d", 16);
	test("%+03d", 0);
	test("%hhd", CHAR_MAX + 42);
	test("%+ jd", INTMAX_MAX);
	test("%03d", -1);
	test("%03.2d", -1);
	test("%.10d", 42);
	test("%+15.4d", 42);
	test("%15.4d", -42);
	test("%zd", 4294967296);
	test("%d", 10);
	test("% d", 10);
	test("%+d", 10);
	test("%.d", 10);
	test("%+.3d", 10);
	test("% 010.3d", 10);
	test("% 010d", 10);
	test("%- 010d", 10);
	test("%-+ 010d", 10);
	// setlocale(LC_ALL, "");
	// test("%-10.👩");
	// test("%-10.👩d");
	// test("%ls", L"Hello");
	// test("%ls", L"👩🏽‍🚒");
	// test("%.3ls", L"👩🏽‍🚒");
	// test("%.5ls", L"👩🏽‍🚒");
	// test("% -010.5ls", L"👩🏽‍🚒");
	// test("% -010.5S", L"👩🏽‍🚒");
}
