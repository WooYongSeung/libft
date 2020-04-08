/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykoh <ykoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 21:04:49 by ykoh              #+#    #+#             */
/*   Updated: 2020/04/08 19:35:29 by ykoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
/*
	t_list	*new;

	new = NULL;
	while (lst)
	{
		ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
		ft_lstdelone(lst, del);
		lst = lst->next;
	}
*/

	const t_list	*lstp = lst;
	void			*is_success;
	t_list			*new;

	new = NULL;
	while (lstp)
	{
		if ((is_success = f(lstp->content)))
			ft_lstadd_back(&new, ft_lstnew(is_success));
		lstp = lstp->next;
	}
	ft_lstclear(&lst, del);
	return (new);
}
