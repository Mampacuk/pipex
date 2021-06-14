/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetchdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:33:05 by aisraely          #+#    #+#             */
/*   Updated: 2021/05/15 14:33:06 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fetchdigit(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (ft_isdigit(*str))
			return (str);
		str++;
	}
	return (NULL);
}
