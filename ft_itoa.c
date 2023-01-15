/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cachatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:49:35 by cachatel          #+#    #+#             */
/*   Updated: 2023/01/11 18:55:56 by cachatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_itoa_malloc(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size = 1;
		n = -n;
	}
	while (n > 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*transform_n(char *result, long tmp, int size)
{
	while (tmp >= 0 && (size + 1) > 1)
	{
		result[--size] = (tmp % 10) + '0';
		tmp = tmp / 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		size;
	int		neg;
	char	*result;
	long	tmp;
	int		nb;

	tmp = (long)n;
	size = ft_itoa_malloc(tmp);
	nb = size;
	result = malloc (sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	neg = 1;
	if (tmp < 0)
	{
		neg = tmp;
		tmp = -tmp;
	}
	result = transform_n(result, tmp, size);
	if (neg < 0)
		result[0] = '-';
	result[nb] = '\0';
	return (result);
}
