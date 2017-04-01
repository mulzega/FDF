/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:20:35 by ljeanner          #+#    #+#             */
/*   Updated: 2017/02/28 16:14:05 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static size_t	ft_count_strings(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static char		**ft_split(char **arr, char *s, char c, size_t k)
{
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	start = 0;
	j = 0;
	while (s[i] && j < k)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			arr[j] = ft_strsub(s, start, i - start);
			j++;
		}
		else
			i++;
	}
	arr[j] = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_count_strings((char *)s, c);
	arr = NULL;
	if (!(arr = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	arr = ft_split(arr, (char*)s, c, i);
	return (arr);
}
