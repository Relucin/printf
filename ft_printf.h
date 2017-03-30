/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: bmontoya <bmontoya@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/30 00:34:49 by bmontoya         ###   ########.fr       */
=======
/*   By: bmontoya <bmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:37:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/29 16:58:43 by bmontoya         ###   ########.fr       */
>>>>>>> 13c4a04b057e381adbd4cb87ade59ea59b313529
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
<<<<<<< HEAD
# include "libft.h"
=======
# include "../libft/libft.h"
>>>>>>> 13c4a04b057e381adbd4cb87ade59ea59b313529
typedef enum	e_flag
{
	ALT = 1,
	ZER = 2,
	NEG = 4,
	SPC = 8,
	PLS = 16
}				t_flag;

typedef enum	e_length
{
	hh = 1,
	h = 2,
	l = 3,
	ll = 4,
	j = 5,
	z = 6,
	L = 7
}				t_length;

typedef struct	s_part
{
	char			*str;
	unsigned char	flags;
	unsigned char	prec : 1;
	int		arg;
	int		width;
	int		pmin;
	int		length;
	int		type;
}				t_part;

typedef int (*t_check)(const char **, t_part *);

#endif
