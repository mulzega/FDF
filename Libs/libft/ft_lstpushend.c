/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:40:51 by ljeanner          #+#    #+#             */
/*   Updated: 2016/12/02 19:11:08 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushend(t_list *tail, const void *data, size_t data_size)
{
	t_list	*new_tail;

	new_tail = ft_lstnew(data, data_size);
	if (tail)
		tail->next = new_tail;
	return (new_tail);
}
