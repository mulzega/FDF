/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:39:16 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/15 14:25:02 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*tmp;
	char	*tmp2;

	tmp = dest;
	tmp2 = (char *)src;
	while (*tmp)
		tmp++;
	while (*tmp2)
	{
		*tmp = *tmp2;
		tmp++;
		tmp2++;
	}
	*tmp = '\0';
	return (dest);
}
