# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 08:44:57 by pmeredyt          #+#    #+#              #
#    Updated: 2022/01/17 18:16:25 by pmeredyt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c get_next_line.c parse_file.c \
	   parse_file_2.c draw_map.c movement.c \
	   animation.c

SRCS_B = main_bonus.c get_next_line_bonus.c parse_file_bonus.c \
	   parse_file_2_bonus.c draw_map_bonus.c movement_bonus.c \
	   animation_bonus.c enemies_bonus.c

SRC_DIR = srcs
BONUS_DIR = bonus
HEADER = include/so_long.h include/so_long_bonus.h


OBJS = $(addprefix $(SRC_DIR)/,$(SRCS:.c=.o))
OBJS_B = $(addprefix $(BONUS_DIR)/,$(SRCS_B:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit
FT =-L libft -lft

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft bonus
	@make -C libft
	$(CC) -o $(NAME) $(OBJS) $(FT) $(MLX) 


bonus:
	@make OBJS="$(OBJS_B)"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft/ clean
	@$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	@make -C libft/ fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
