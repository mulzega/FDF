/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:08:04 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/07 18:08:43 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isskip(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (ft_isskip(s[i]))
		i++;
	while (ft_isskip(s[len - 1]))
		len--;
	if (i < len)
		str = ft_strsub(s, i, len - i);
	else
		str = ft_strnew(0);
	return (str);
}
