/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:10:25 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/06 19:14:17 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*res;

	res = (char *) str;
	while (*res)
	{
		if (*res == c)
			return (res);
		res++;
	}
	if (c != '\0')
		return (NULL);
	else
		return (res);
}
