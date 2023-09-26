# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 18:44:00 by izanoni           #+#    #+#              #
#    Updated: 2023/09/25 19:26:56 by izanoni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INC)
XFLAGS =  -lmlx -lXext -lX11
RM = rm -f

FILES = 

OBJ = $(FILES:%.c=%.o)

BONUS = 

OBJ_B = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

bonus: $(OBJ_B)
	
clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re