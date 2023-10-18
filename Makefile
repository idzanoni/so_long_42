# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:44:00 by izanoni           #+#    #+#              #
#    Updated: 2023/10/18 15:56:45 by izanoni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(LIBFT)  -I$(FT_PRINTF) -I$(GNL)
XFLAGS =  -lmlx -lXext -lX11
RM = rm -f

LIBFT = ./libs/libft
FT_PRINTF = ./libs/ft_printf
GNL = ./libs/get_next_line

FILES = sl_checks_2.c \
		sl_checks.c \
		sl_finish.c \
		sl_init.c \
		sl_map_key.c \
		sl_sprites.c \
		so_long.c
OBJS = $(FILES:%.c=%.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@make -C $(GNL)
	@$(CC) $(OBJS) $(CFLAGS) $(GNL)/get_next_line.a $(FT_PRINTF)/libftprintf.a $(LIBFT)/libft.a -o $(NAME) $(XFLAGS)

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(FT_PRINTF)
	@make clean -C $(GNL)
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(FT_PRINTF)
	@make fclean -C $(GNL)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re