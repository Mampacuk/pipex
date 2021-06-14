/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:22:28 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/01 22:23:11 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t cnt)
{
	unsigned char	*str1copy;
	unsigned char	*str2copy;
	unsigned char	cc;

	cc = (unsigned char)c;
	str1copy = (unsigned char *) dest;
	str2copy = (unsigned char *) src;
	while (cnt--)
	{
		*str1copy = *str2copy;
		if (*str1copy == cc)
			return (str1copy + 1);
		str1copy++;
		str2copy++;
	}
	return (NULL);
}
