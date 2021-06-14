/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:20:27 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/02 19:20:29 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] && n)
	{
		j = 0;
		size = n;
		while (str[i + j] == to_find[j])
		{
			if (!size)
				break ;
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
			size--;
		}
		i++;
		n--;
	}
	return (NULL);
}
