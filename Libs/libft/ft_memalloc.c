/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:18:10 by ljeanner          #+#    #+#             */
/*   Updated: 2017/03/01 16:19:01 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *block;

	block = (void *)malloc(size);
	if (block == NULL)
		return (NULL);
	else
		ft_memset(block, 0, size);
	return (block);
}
