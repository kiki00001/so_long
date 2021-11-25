# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/10 10:42:23 by heahn             #+#    #+#              #
#    Updated: 2021/11/04 04:02:27 by heahn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c ft_img.c ft_itoa.c get_next_line.c map_error_check.c map_init.c move_player.c move_reset.c put_img.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

RM	= rm -rf
LIB = ar rcu
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTIONS = -L./mlx -lmlx -framework OpenGL -framework AppKit


all	: $(NAME)

$(NAME) : $(OBJS)
	@echo "==COMPILE $(NAME)=="
	@$(CC) $(CFLAGS) $(OPTIONS) -o $(NAME) $(OBJS)



clean : 
	@echo "==REMOVE OBJECT FILE=="
	@$(RM) $(OBJS)

fclean : clean
	@echo "==REMOVE $(NAME)=="	
	@$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
