/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mulzega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:10:58 by mulzega           #+#    #+#             */
/*   Updated: 2017/03/15 16:29:23 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include "libft.h"
# define BUFF_SIZE 10000

typedef struct		s_gnl
{
	char			*str;
	int				fd;
	struct s_gnl	*next;
	struct s_gnl	*prw;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
