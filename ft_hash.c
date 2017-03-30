/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:18:19 by bmontoya          #+#    #+#             */
/*   Updated: 2017/03/20 14:29:35 by bmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct	s_hash
{
	void		**map;
	size_t		size;
}				t_hash;

t_hash	*ft_hashnew(size_t size)
{
	t_hash *hash;

	hash = malloc(sizeof(t_hash));
	hash->map = (void**)malloc(sizeof(void*) * size);

	return (hash);
}
