/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:28:48 by amamian           #+#    #+#             */
/*   Updated: 2021/10/09 20:55:20 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoalen(int n)
{
	size_t	ret;

	ret = (n <= 0);
	while (n)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;
	bool	neg;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_itoalen(n);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	neg = (n < 0);
	if (neg)
		n = -n;
	ret[len] = '\0';
	while (len)
	{
		if (!--len && neg)
			ret[len] = '-';
		else
		{
			ret[len] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (ret);
}
