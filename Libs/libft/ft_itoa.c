/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:25:49 by ljeanner          #+#    #+#             */
/*   Updated: 2016/11/15 14:20:23 by ljeanner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(int n)
{
	size_t	len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long long	tmp;

	tmp = n;
	len = ft_getlen(n);
	if (tmp == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	len--;
	str[len--] = tmp % 10 + '0';
	while (tmp /= 10)
		str[len--] = tmp % 10 + '0';
	if (n < 0)
		str[len] = '-';
	return (str);
}
