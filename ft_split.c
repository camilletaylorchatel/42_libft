/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:27:46 by cachatel          #+#    #+#             */
/*   Updated: 2023/01/11 17:08:30 by cachatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isin(char c, const char *s, int index)
{
	if (s[index] == c)
		return (index);
	return (-1);
}

int	ft_malloc_tab(const char *s, char c)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isin(c, s, i) != -1)
			i++;
		if (s[i])
		{
			nb++;
			while (s[i] && ft_isin(c, s, i) == -1)
				i++;
		}
	}
	return (nb);
}

char	*ft_stock_word(char c, const char *s, int i)
{
	char	*dst;
	int		j;

	j = i;
	while (s[j] && ft_isin(c, s, j) == -1)
		j++;
	j -= i;
	dst = malloc(sizeof(char) * j + 1);
	j = 0;
	while (s[i] && ft_isin(c, s, i) == -1)
		dst[j++] = s[i++];
	dst[j] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c)
{	
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_malloc_tab(s, c) + 1));
	i = 0;
	j = 0;
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && ft_isin(c, s, i) != -1)
			i++;
		if (s[i])
		{
			tab[j] = ft_stock_word(c, s, i);
			i += ft_strlen(tab[j++]);
		}
	}
	tab[j] = NULL;
	return (tab);
}
