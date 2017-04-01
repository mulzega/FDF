/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:05:32 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/01 15:26:43 by mulzega          ###   ########.fr       */
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
	TMP = NULL;
	while (get_next_line(fd, &temp))
	{
		if (!(TMP) && (XMAX = ft_xmax(temp)))
			TMP = ft_strdup(temp);
		else
			TMP = ft_strjoinfree(TMP, temp);
		if (XMAX != ft_xmax(temp))
		{
			ft_putstr("map file error\n");
			exit(0);
		}
		TMP = ft_strjoinfree(TMP, "\n");
		free(LINE);
		YMAX++;
	}
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
		{
			ft_putstr("map file doesn't exist\n");
			exit (0);
		}
		ft_fdf(&e);
	}
	if (ac < 2 || ac > 2)
		ft_putstr("usage : ./fdf [map_file]\n");
	return (0);
}
