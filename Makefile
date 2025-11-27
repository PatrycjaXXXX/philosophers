# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 10:30:52 by psmolich          #+#    #+#              #
#    Updated: 2025/11/27 13:51:59 by psmolich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC := cc
CFLAGS := -Wall -Wextra -Werror -pthread

NAME := philo

SRC := $(wildcard utils/*) $(wildcard ./*.c)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all
