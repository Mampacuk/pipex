/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:50:35 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/09 20:50:36 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(const char *msg, int code)
{
	if (msg)
		ft_putstr_fd((char *)msg, 2);
	else
		perror(NULL);
	exit(code);
}
