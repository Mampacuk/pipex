/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 22:46:32 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/01 23:08:21 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*str1copy;
	const char	*str2copy;

	str1copy = str1;
	str2copy = str2;
	if (str1copy == NULL && str1copy == str2copy)
		return (str1);
	if (str1copy < str2copy)
	{
		while (n--)
			*str1copy++ = *str2copy++;
	}
	else
	{
		str1copy = str1copy + n - 1;
		str2copy = str2copy + n - 1;
		while (n--)
			*str1copy-- = *str2copy--;
	}
	return (str1);
}
