/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 18:04:31 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/07 18:05:10 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_htoi(char *s)
{
	int		i;
	int		n;
	char	curr;

	i = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	n = 0;
	while (s[i] != '\0')
	{
		curr = s[i];
		if (ft_isalpha(curr))
			curr = ft_tolower(curr) - 'a' + 10;
		else if (ft_isdigit(curr))
			curr = curr - '0';
		n = n * 0x10 + curr;
		++i;
	}
	return (n);
}
