/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:05:32 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/12 14:51:58 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_xmax(char *temp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (temp[i])
	{
		while (temp[i] == 32)
			i++;
		if (ft_isalpha(temp[i]) == 1)
			ft_error(3);
		if (temp[i] != 32 && temp[i])
		{
			j++;
			while (temp[i] != 32 && temp[i])
				i++;
		}
	}
	return (j);
}

void	ft_parse(t_env *e, int fd)
{
	char	*temp;

	YMAX = 0;
	while (get_next_line(fd, &temp))
	{
		if (!(TMP) && (XMAX = ft_xmax(temp)))
			TMP = ft_strdup(temp);
		else
			TMP = ft_strjoinfree(TMP, temp);
		if (XMAX != ft_xmax(temp))
			ft_error(3);
		TMP = ft_strjoinfree(TMP, "\n");
		free(LINE);
		YMAX++;
	}
	if (YMAX == 0)
		ft_error(3);
	TMP = ft_strjoinfree(TMP, "\0");
	Z = ft_split_whitespaces(TMP);
	LINE = ft_strsplit(TMP, '\n');
	free(TMP);
}

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	t_env	e;

	i = 0;
	e.z = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
			ft_parse(&e, fd);
		else
			ft_error(1);
		ft_fdf(&e);
	}
	if (ac < 2 || ac > 2)
		ft_error(2);
	return (0);
}
