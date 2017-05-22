/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 17:25:59 by bmontoya          #+#    #+#             */
/*   Updated: 2017/02/28 13:15:30 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int count;

	count = 0;
	while (count < n)
	{
		if (*src)
			dst[count++] = *src++;
		else
			dst[count++] = '\0';
	}
	return (dst);
}
