/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:41:03 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/22 15:57:32 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*begin_lst;

	if (!lst)
		return (lst);
	tmp = f(lst);
	lst = lst->next;
	new = ft_lstnew(tmp->content, tmp->content_size);
	if (!new)
		return (new);
	begin_lst = new;
	while (lst)
	{
		tmp = f(lst);
		lst = lst->next;
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!new->next)
			return (new->next);
		new = new->next;
	}
	return (begin_lst);
}
