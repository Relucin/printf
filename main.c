/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:20:27 by bmontoya          #+#    #+#             */
/*   Updated: 2017/04/06 01:09:14 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include <stdio.h>
// #include "ft_printf.h"
#include "ft_darray.h"

/*#define SELF 1
#define	REAL 2
void	ft_printf_wstringtests(int i)
{
	wchar_t *str = L"ᆀǑǒǛڕiۂᅿᆀᆁ";
	char	*fmt = "%.4ls\n";

	if (i & SELF)
		ft_printf(fmt, str);
	if (i & REAL)
		printf(fmt, str);
}*/

int		main(void)
{
	t_darr	*test;
	long	*tmp;
	// int		i = 0;
	setlocale(LC_ALL, "");
	//ft_printf_wstringtests(3);
	test = ft_darrnew(2, sizeof(long));
	ft_darraddback(test, 20);
	ft_darraddback(test, 21);
	ft_darraddback(test, 22);
	ft_darraddback(test, 23);
	ft_darraddback(test, 24);
	ft_darraddback(test, 25);
	ft_darraddback(test, 26);
	ft_darraddback(test, 27);
	ft_darraddback(test, 1000002323224);
	/*ft_darraddback(test, 'j');
	ft_darraddback(test, 'k');
	ft_darraddback(test, 'l');
	ft_darraddback(test, 'm');
	ft_darraddback(test, 'n');
	ft_darraddback(test, 'o');
	ft_darraddback(test, 'p');
	ft_darraddback(test, 'q');
	ft_darraddback(test, 'r');
	ft_darraddback(test, 's');
	ft_darraddback(test, 't');
	ft_darraddback(test, 'u');
	ft_darraddback(test, '\0');*/
	tmp = (long*)test->array;
	// while (i < ft_darrlen(test))
	// {
	printf("%ld\n", ft_darrget(test, 8));
	// }
}
