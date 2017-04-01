/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:03:19 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/15 14:28:54 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	k;

	dst_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	k = 0;
	if (n <= dst_size)
		return (src_size + n);
	while (i < (n - 1) && dest[i])
		i++;
	while (i < (n - 1) && src[k])
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dst_size + src_size);
}
