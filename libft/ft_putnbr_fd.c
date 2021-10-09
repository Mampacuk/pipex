/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:45:22 by amamian           #+#    #+#             */
/*   Updated: 2021/09/21 13:08:13 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	exp;

	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n == INT_MIN)
		return (ft_putstr_fd("2147483648", fd));
	if (n < 0)
		n = -n;
	exp = 1;
	while (exp <= n / 10)
		exp *= 10;
	while (exp)
	{
		ft_putchar_fd((n / exp) + '0', fd);
		n %= exp;
		exp /= 10;
	}
}
