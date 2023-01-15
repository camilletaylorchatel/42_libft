/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:22:13 by cachatel          #+#    #+#             */
/*   Updated: 2022/12/26 20:10:25 by cachatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst,
		const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	init_size ;

	if (dstsize == 0 && dst == NULL)
		return (ft_strlen(src));
	init_size = ft_strlen(dst);
	if (dstsize <= init_size)
	{	
		return (dstsize + ft_strlen(src));
	}
	if (!src)
		return (dstsize);
	i = 0;
	while (src[i] && i < (dstsize - init_size - 1))
	{
		dst[init_size + i] = src[i];
		i++;
	}
	dst[init_size + i] = '\0';
	return (init_size + ft_strlen(src));
}
