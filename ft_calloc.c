/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:04:07 by cachatel          #+#    #+#             */
/*   Updated: 2023/01/11 17:10:49 by cachatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	result = malloc (count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, count * size);
	return (result);
}
