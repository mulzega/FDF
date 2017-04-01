/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:05:41 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/01 14:53:14 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hsl(t_env *e, int x)
{
	if (H >= 120 && H < 180)
	{
		COLOR = ft_strjoin("00", ft_itoa(255));
		COLOR = ft_strjoin(COLOR, ft_itoa(x));
	}
	else if (H >= 180 && H < 240)
	{
		COLOR = ft_strjoin("00", ft_itoa(x));
		COLOR = ft_strjoin(COLOR, ft_itoa(255));
	}
	else if (H >= 240 && H < 300)
	{
		COLOR = ft_strjoin(ft_itoa(x), "00");
		COLOR = ft_strjoin(COLOR, ft_itoa(255));
	}
	else
	{
		COLOR = ft_strjoin(ft_itoa(255), "00");
		COLOR = ft_strjoin(COLOR, ft_itoa(x));
	}
}

void	ft_get_h(t_env *e, int w)
{
	int x;

	H = (ft_atoi(Z[w]) * 360) / (ZMAX - ZMIN);
	x = (255 * (1 - abs((H / 60) % 2 - 1)));
	if (H >= 0 && H < 60)
	{
		COLOR = ft_strjoin(ft_itoa(255), ft_itoa(x));
		COLOR = ft_strjoin(COLOR, "00");
	}
	else if (H >= 60 && H < 120)
	{
		COLOR = ft_strjoin(ft_itoa(x), ft_itoa(255));
		COLOR = ft_strjoin(COLOR, "00");
	}
	else
		ft_hsl(e, x);
}

void	ft_line(t_env *e)
{
	int		dy;
	int		err;
	int		e2;
	int		sx;
	int		sy;

	sx = X1 < X2 ? 1 : -1;
	dy = abs(Y2 - Y1);
	sy = Y1 < Y2 ? 1 : -1;
	err = (DX > dy ? DX : -dy) / 2;
	while (!(X1 == X2 && Y1 == Y2))
	{
		mlx_pixel_put(MLX, WIN, X1, Y1, ft_atoi(COLOR));
		e2 = err;
		if (e2 > -DX)
		{
			err -= dy;
			X1 += sx;
		}
		if (e2 < dy)
		{
			err += DX;
			Y1 += sy;
		}
	}
}

void	ft_coord(t_env *e, int y, int x, int w)
{
	if (x < XMAX - 1)
	{
		X1 = 1 * ((x * ZOOM) + PADG) - 1 * ((y * ZOOM) + PAHB);
		Y1 = -(ft_atof(Z[w]) * ((ZOOM / 3) + 1) * ZZ) + 0.5 *
			((x * ZOOM) + PADG) + 0.5 * ((y * ZOOM) + PAHB);
		X2 = 1 * (((x + 1) * ZOOM) + PADG) - 1 * ((y * ZOOM) + PAHB);
		Y2 = -(ft_atof(Z[w + 1]) * ((ZOOM / 3) + 1) * ZZ) + 0.5 *
			(((x + 1) * ZOOM) + PADG) + 0.5 * ((y * ZOOM) + PAHB);
		DX = abs(X2 - X1);
		ft_line(e);
	}
	if (y < YMAX - 1)
	{
		X1 = 1 * ((x * ZOOM) + PADG) - 1 * ((y * ZOOM) + PAHB);
		Y1 = -(ft_atof(Z[w]) * ((ZOOM / 3) + 1) * ZZ) + 0.5 *
			((x * ZOOM) + PADG) + 0.5 * ((y * ZOOM) + PAHB);
		X2 = 1 * ((x * ZOOM) + PADG) - 1 * (((y + 1) * ZOOM) + PAHB);
		Y2 = -(ft_atof(Z[w + XMAX]) * ((ZOOM / 3) + 1) * ZZ) + 0.5 *
			((x * ZOOM) + PADG) + 0.5 * (((y + 1) * ZOOM) + PAHB);
		DX = abs(X2 - X1);
		ft_line(e);
	}
}

void	ft_draw(t_env *e)
{
	int		y;
	int		x;
	int		w;

	y = 0;
	w = 0;
	while (y < YMAX)
	{
		x = 0;
		while (x < XMAX)
		{
			if (L == 0)
				ft_get_h(e, w);
			ft_coord(e, y, x, w);
			w++;
			x++;
		}
		y++;
	}
}
