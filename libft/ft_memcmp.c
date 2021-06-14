/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:33:09 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/01 22:33:10 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*str1copy;
	unsigned char	*str2copy;

	str1copy = (unsigned char *) str1;
	str2copy = (unsigned char *) str2;
	while (n--)
	{
		if (*str1copy != *str2copy)
			return (*str1copy - *str2copy);
		str1copy++;
		str2copy++;
	}
	return (0);
}
