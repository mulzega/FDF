/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:39:37 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/22 15:56:58 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (f)
	{
		new = lst;
		while (new)
		{
			tmp = new;
			new = new->next;
			f(tmp);
		}
	}
}
