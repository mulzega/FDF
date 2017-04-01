/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:00:14 by mulzega           #+#    #+#             */
/*   Updated: 2017/03/16 13:32:10 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			test_tmp(char **tmp, char **line)
{
	char	*str;
	char	*tmp2;
	int		i;
	char	*temp;

	str = NULL;
	tmp2 = NULL;
	temp = NULL;
	if ((tmp2 = ft_strchr(*tmp, '\n')))
	{
		i = tmp2 - *tmp;
		str = ft_strsub(*tmp, 0, i);
		*line = ft_strdup(str);
		ft_strdel(&str);
		temp = ft_strsub(*tmp, i + 1, ft_strlen(*tmp) - i);
		ft_strdel(tmp);
		*tmp = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	return (0);
}

int			this_is_the_end(char **tmp, char **line)
{
	*line = ft_strsub(*tmp, 0, ft_strlen(*tmp));
	ft_strdel(tmp);
	return (1);
}

int			gnl(const int fd, char **line, char **tmp, int ret)
{
	char	*tmp2;
	char	buf[BUFF_SIZE + 1];

	tmp2 = NULL;
	if ((*tmp && **tmp) && test_tmp(tmp, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!*tmp)
			*tmp = ft_strdup(buf);
		else
		{
			tmp2 = ft_strjoin(*tmp, buf);
			ft_strdel(tmp);
			*tmp = ft_strdup(tmp2);
			ft_strdel(&tmp2);
		}
		return (gnl(fd, line, tmp, ret));
	}
	if (ret < 0)
		return (-1);
	if (*tmp && **tmp)
		return (this_is_the_end(tmp, line));
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*tmp = NULL;
	int			ret;

	ret = 0;
	if (fd < 0)
		return (-1);
	return (gnl(fd, line, &tmp, ret));
	return (-1);
}
