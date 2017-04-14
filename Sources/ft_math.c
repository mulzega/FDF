/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:04:51 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/14 13:24:57 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_get_zmax(t_env *e)
{
	int		i;

	i = 0;
	while (i < XMAX * YMAX)
	{
		if (ft_atoi(Z[i]) > ZMAX)
			ZMAX = ft_atoi(Z[i]) + 3;
		if (ft_atoi(Z[i]) < ZMIN)
			ZMIN = ft_atoi(Z[i]) - 2;
		i++;
	}
}

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("map file doesn't exist\n");
	if (i == 2)
		ft_putstr("usage : ./fdf [map_file]\n");
	if (i == 3)
		ft_putstr("map file error\n");
	else
		exit(0);
	exit(0);
}
