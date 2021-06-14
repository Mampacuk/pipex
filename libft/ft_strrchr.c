/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 20:09:38 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/06 19:16:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*res;
	char	*beginning;

	res = (char *) str;
	beginning = (char *) str;
	while (*res)
		res++;
	if (c == '\0')
		return (res);
	res--;
	while (*res)
	{
		if (*res == c)
			return (res);
		if (res == beginning)
			break ;
		res--;
	}
	return (NULL);
}
