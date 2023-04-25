# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 23:31:43 by ogenc             #+#    #+#              #
#    Updated: 2023/04/25 23:50:17 by ogenc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/mandatory/main.c \
./srcs/mandatory/map_functions.c \
./srcs/mandatory/add_imgs.c \
./srcs/mandatory/check_functions.c \
./srcs/mandatory/check_functions2.c \
./srcs/mandatory/check_functions3.c \
./srcs/mandatory/utils.c \
./srcs/mandatory/loop_functions.c \
./srcs/mandatory/loop_functions2.c \
./srcs/mandatory/render_functions.c \
./srcs/mandatory/move_functions.c


SRCBS = ./srcs/bonus/main_bonus.c \
./srcs/bonus/map_functions_bonus.c \
./srcs/bonus/add_imgs_bonus.c \
./srcs/bonus/check_functions_bonus.c \
./srcs/bonus/check_functions2_bonus.c \
./srcs/bonus/check_functions3_bonus.c \
./srcs/bonus/utils_bonus.c \
./srcs/bonus/utils2_bonus.c \
./srcs/bonus/loop_functions_bonus.c \
./srcs/bonus/loop_functions2_bonus.c \
./srcs/bonus/render_functions_bonus.c \
./srcs/bonus/move_functions_bonus.c

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -framework AppKit -framework OpenGL -L./library/mlx -lmlx
MLX = ./library/mlx/libmlx.a
FT_PRINTF = ./library/42-printf/libftprintf.a
GET_NEXT_LINE = ./library/42-get_next_line/get_next_line.c ./library/42-get_next_line/get_next_line_utils.c
RM = rm -rf
LIBC = ar -rcs

all: $(MLX) $(NAME)

$(NAME): $(SRCS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
	@echo "-*-*-*- OK -*-*-*-"

bonus : $(SRCBS) $(MLX) $(FT_PRINTF) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCBS) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(NAME)
	@echo "-*-*-*- OK -*-*-*-"

$(MLX) :
	@make -C ./library/mlx

$(FT_PRINTF) :
	@make -C ./library/42-printf

clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./library/mlx
	@make fclean -C ./library/42-printf

re: fclean all

.PHONY: all bonus clean fclean re .c.o