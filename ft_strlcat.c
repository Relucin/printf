/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:15:46 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/03 17:48:13 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ilen;

	if (!size)
		return (ft_strlen(src));
	ilen = 0;
	while (*dst && --size)
	{
		dst++;
		ilen++;
	}
	ilen += ft_strlen(src);
	if (!size)
		return (++ilen);
	size--;
	while (size--)
		*dst++ = *src++;
	*dst = '\0';
	return (ilen);
}
