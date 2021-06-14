/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:41:42 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/01 22:42:09 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str1copy;
	char	*str2copy;

	str1copy = dest;
	str2copy = (char *) src;
	while (n-- && !(str1copy == NULL && str1copy == str2copy))
	{
		*str1copy = *str2copy;
		str1copy++;
		str2copy++;
	}
	return (dest);
}
