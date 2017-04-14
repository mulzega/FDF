/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 10:07:59 by mulzega           #+#    #+#             */
/*   Updated: 2017/04/14 13:23:41 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../Libs/libft/libft.h"
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

# define MLX e->mlx
# define WIN e->win
# define X1	e->x1
# define N e->n
# define Y1 e->y1
# define X2 e->x2
# define Y2 e->y2
# define XMAX e->xmax
# define YMAX e->ymax
# define ZMAX e->zmax
# define ZMIN e->zmin
# define ZZ e->zz
# define H e->h
# define TMP e->tmp
# define LINE e->line
# define ZOOM e->zoom
# define Z e->z
# define PADG e->padg
# define PAHB e->pahb
# define COLOR	e->color
# define X e->x
# define L e->l
# define DX e->dx
# define BUFF_SIZE	16
# define WIN_SIZE	1000

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		n;
	int		x;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		xmax;
	int		ymax;
	int		zmax;
	int		zmin;
	int		h;
	int		zoom;
	int		padg;
	int		pahb;
	int		l;
	float	zz;
	char	*color;
	char	*tmp;
	char	**z;
	char	**line;
}				t_env;

int				ft_mouse_hook(int mousecode);
int				ft_key_hook(int keycode, t_env *e);
int				ft_key_hook2(int keycode, t_env *e);
int				ft_message(t_env *e);
void			ft_coord(t_env *e, int y, int x, int w);
void			ft_line(t_env *e);
void			ft_get_h(t_env *e, int w);
void			ft_hsl(t_env *e, int x);
int				ft_xmax(char *temp);
void			ft_parse(t_env *e, int fd);
int				main(int ac, char **av);
void			ft_get_zmax(t_env *e);
void			ft_free(t_env *e);
void			ft_error(int i);
int				ft_fdf(t_env *e);
void			ft_draw(t_env *e);

#endif
