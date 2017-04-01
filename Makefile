# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mulzega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 14:52:15 by mulzega           #+#    #+#              #
#    Updated: 2017/04/01 15:30:27 by mulzega          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = Sources/ft_parse.c Sources/ft_init.c Sources/ft_draw.c Sources/ft_math.c

OBJ = $(SRC:.c=.o)

CF = gcc -Wall -Werror -Wextra

LIBS = -LLibs/libft/ -LLibs/minilibx_macos/

$(NAME): $(OBJ)
	@make -C Libs/libft
	@make -C Libs/minilibx_macos
	@$(CF) $(LIBS) -lft -lmlx -framework OpenGL -framework AppKit -o $@ $^
#   @"\033[32m[OK]\033[0m"#
	@echo fdf well compiled

all: $(NAME)

%.o: %.c
	@$(CF) -o $@ -c $<

clean:
	@make clean -C Libs/libft
	@make clean -C Libs/minilibx_macos
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C Libs/libft
	@rm -f $(NAME)

re: fclean all
