/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:29:24 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/22 16:01:18 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*tmp;

	if (alst && del)
	{
		new = *alst;
		while (new)
		{
			tmp = new;
			new = new->next;
			ft_lstdelone(&tmp, del);
		}
		*alst = NULL;
	}
}
