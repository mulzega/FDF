/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:55:02 by mulzega           #+#    #+#             */
/*   Updated: 2017/02/16 15:31:11 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*p;

	p = (char *)str;
	p = p + ft_strlen(str);
	while ((p != str) && (*p != (char)c))
		p--;
	if (*p == (char)c)
		return ((char *)p);
	return (NULL);
}
