# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 17:38:35 by anremiki          #+#    #+#              #
#    Updated: 2022/04/03 00:19:54 by cmarouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c \
		utils/parsing_utils_1.c \
		srcs/parsing_1.c \

INCLUDES = ./includes/

OBJS = ${SRCS:.c=.o}

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES) -lm

MLXFLAGS = ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/

NAME = cub3d

CC = gcc

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME): $(OBJS)
		@make -C ./minilibx
		@make -C ./libft
		$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) libft/libft.a -o $(NAME)

clean:
		make clean -C ./minilibx
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME)
		$(RM) ./minilibx/libmlx_Linux.a
		$(RM) ./minilibx/libmlx.a
		make fclean -C ./libft

re:		fclean all

.PHONY: all clean fclean re

.SILENT: all clean fclean re
