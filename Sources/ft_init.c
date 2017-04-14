/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 11:06:03 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/01 14:56:57 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_message(t_env *e)
{
	mlx_string_put(MLX, WIN, 10, 10, 0xFFFFFF, "ZOOM : Q & W");
	mlx_string_put(MLX, WIN, 10, 30, 0xFFFFFF, "HIGH : A & S");
	mlx_string_put(MLX, WIN, 10, 50, 0xFFFFFF, "COLOR : Z & X");
	mlx_string_put(MLX, WIN, 200, 10, 0xFFFFFF, "INIT : ENTER");
	mlx_string_put(MLX, WIN, 200, 30, 0xFFFFFF, "COLOR MODE : 0");
	mlx_string_put(MLX, WIN, 200, 50, 0xFFFFFF, "CHANGE COLOR : 1 TO 6");
	mlx_string_put(MLX, WIN, 515, 16, 0xFFFFFF, "^");
	mlx_string_put(MLX, WIN, 515, 21, 0xFFFFFF, "|");
	mlx_string_put(MLX, WIN, 420, 30, 0xFFFFFF, "MOVE : <---->");
	mlx_string_put(MLX, WIN, 515, 39, 0xFFFFFF, "|");
	mlx_string_put(MLX, WIN, 515, 45, 0xFFFFFF, "v");
	return (0);
}

int		ft_key_hook2(int keycode, t_env *e)
{
	if (keycode == 1)
		ZZ = ZZ + 0.2;
	if (keycode == 0)
		ZZ = ZZ - 0.2;
	if (keycode == 36)
		ft_fdf(e);
	if (keycode == 82)
	{
		if (L == 0)
			L = 1;
		else if (L == 1)
			L = 0;
		COLOR = ft_strdup("16711422");
	}
	if (keycode == 83)
		COLOR = ft_strdup("16646144");
	if (keycode == 84)
		COLOR = ft_strdup("15991037");
	if (keycode == 85)
		COLOR = ft_strdup("4605");
	if (keycode == 86)
		COLOR = ft_strdup("60669");
	if (keycode == 87)
		COLOR = ft_strdup("64802");
	return (0);
}

int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_error(4);
	if (keycode == 7)
		ZMAX = ZMAX + 5;
	if (keycode == 6 && ZMAX > 5)
		ZMAX = ZMAX - 5;
	if (keycode == 12 && ZOOM > 1)
		ZOOM = ZOOM - 1;
	if (keycode == 13)
		ZOOM = ZOOM + 1;
	if (keycode == 124)
		PADG = PADG + 50;
	if (keycode == 123)
		PADG = PADG - 50;
	if (keycode == 126)
		PAHB = PAHB - 50;
	if (keycode == 125)
		PAHB = PAHB + 50;
	if (keycode == 88)
		COLOR = ft_strdup("16643072");
	ft_key_hook2(keycode, e);
	mlx_clear_window(MLX, WIN);
	ft_draw(e);
	ft_message(e);
	return (0);
}

int		ft_mouse_hook(int mousecode)
{
	if (mousecode == 2)
		ft_error(5);
	return (0);
}

int		ft_fdf(t_env *e)
{
	MLX = mlx_init();
	ZOOM = 20;
	PADG = 800;
	PAHB = 150;
	ZMAX = 0;
	ZZ = 1;
	COLOR = NULL;
	L = 0;
	if (N != 344)
		WIN = mlx_new_window(MLX, 1500, 1500, "fdf_42");
	N = 344;
	mlx_clear_window(MLX, WIN);
	ft_get_zmax(e);
	ft_draw(e);
	ft_message(e);
	mlx_hook(WIN, 2, KeyPressMask, ft_key_hook, e);
	mlx_mouse_hook(WIN, ft_mouse_hook, e);
	mlx_loop(MLX);
	return (0);
}
