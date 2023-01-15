/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:09:37 by cachatel          #+#    #+#             */
/*   Updated: 2023/01/11 17:04:46 by cachatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isin_strim(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_find_begin(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_isin_strim(s1[i], set) == -1)
			return (i);
		i++;
	}
	return (i);
}

int	ft_find_end(const char *s1, const char *set)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	len = len - 1;
	while (len > 0)
	{
		if (ft_isin_strim(s1[len], set) == -1)
			return (len);
		len --;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		j;
	char	*dst;
	int		size;

	if (!s1 || !set)
		return (NULL);
	i = ft_find_begin(s1, set);
	len = ft_find_end(s1, set);
	if (i >= len)
		size = 0;
	else
		size = (len - i) + 1;
	j = 0;
	dst = malloc(sizeof(char) * size + 1);
	if (!dst)
		return (NULL);
	while (i <= len)
		dst[j++] = s1[i++];
	dst[j] = '\0';
	return (dst);
}
