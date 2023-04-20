# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 16:55:30 by ogenc             #+#    #+#              #
#    Updated: 2023/01/10 16:56:14 by ogenc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:%.c=%.o)
FLAGS = -Wall -Wextra -Werror
$(NAME)	: $(OBJS)
		$(CC) $(FLAGS) -c $(SRCS) -I./
		ar rc $(NAME) $(OBJS)
all	:$(NAME)
clean:
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
re:	fclean all
