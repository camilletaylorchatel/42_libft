/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:12:11 by cachatel          #+#    #+#             */
/*   Updated: 2023/01/11 18:06:38 by cachatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{	
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!len && (!needle || !haystack))
		return (NULL);
	if (needle[j])
	{
		while (haystack[i] && i < len)
		{
			while (haystack[i + j] == needle[j] && ((i + j) < len))
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
			}
			i++;
			j = 0;
		}
		return (NULL);
	}
	else
		return ((char *)haystack);
}
