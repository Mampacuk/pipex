/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:32:23 by amamian           #+#    #+#             */
/*   Updated: 2021/09/21 13:10:48 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	void	*fout;
	t_list	*lstp;
	t_list	*new;

	ret = NULL;
	lstp = lst;
	while (lstp)
	{
		fout = f(lstp->content);
		if (fout)
		{
			new = ft_lstnew(fout);
			if (!new)
			{
				ft_lstclear(&ret, del);
				return (NULL);
			}
			ft_lstadd_back(&ret, new);
		}
		lstp = lstp->next;
	}
	return (ret);
}
