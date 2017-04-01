/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:04:51 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/01 14:55:23 by mulzega          ###   ########.fr       */
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
