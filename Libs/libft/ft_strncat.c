/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:46:16 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/15 14:33:18 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*tmp;
	char	*tmp2;

	tmp = dest;
	tmp2 = (char *)src;
	while (*tmp)
		tmp++;
	i = 0;
	while (*tmp2 && (i < n))
	{
		*tmp = *tmp2;
		tmp++;
		tmp2++;
		i++;
	}
	*tmp = '\0';
	return (dest);
}
