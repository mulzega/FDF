/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:16:36 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/18 18:01:02 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	str = (char *)haystack;
	len = ft_strlen(needle);
	while (str[i] && ((len + i) <= n))
	{
		if (!ft_strncmp(&str[i], needle, len))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
