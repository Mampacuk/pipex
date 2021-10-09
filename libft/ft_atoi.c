/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:49:18 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/09 20:49:30 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	ret;
	bool				neg;

	ret = 0;
	while (ft_isspace(*str))
		str++;
	neg = (*str == '-');
	if (neg || *str == '+')
		str++;
	ret = 0;
	while (ft_isdigit(*str))
		ret = ret * 10 + (*str++ - '0');
	if (ret > LONG_MAX && !neg)
		return (-1);
	if (ret > LONG_MAX - 1 && neg)
		return (0);
	if (neg)
		return (-ret);
	return (ret);
}
