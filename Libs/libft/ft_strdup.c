/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:34:40 by mulzega           #+#    #+#             */
/*   Updated: 2017/03/13 16:56:52 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	return (ft_strcpy(s2, src));
}
