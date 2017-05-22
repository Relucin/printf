/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 00:28:02 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/02 00:47:35 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *ns;
	char *hold;

	if (!(ns = (char*)malloc(len + 1)))
		return (NULL);
	hold = ns;
	len += start;
	while (start < len)
		*ns++ = s[start++];
	*ns = '\0';
	return (hold);
}
