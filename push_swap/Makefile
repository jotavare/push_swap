# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotavare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 01:22:30 by jotavare          #+#    #+#              #
#    Updated: 2023/03/14 03:16:56 by jotavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFTPRINTF = ./utilities/libftprintf.a

# COLORS
GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1m

NAME = 	push_swap.a
SRCS =	./algorithm/*.c \
		./functions/*.c \
		./operations/*.c \
		./utilities/*.c \
		./push_swap.c

OBJS = $(SRCS:%.c=%.o)

# MAKE
all: $(NAME)

$(LIBFTPRINTF):
	$(MAKE) -C ./utilities

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o push_swap
	@echo "$(GREEN) [All files compiled!] $(BOLD)"
	@echo "$(GREEN) [./push_swap 1 2 3 4 5] $(BOLD)"

clean:
	$(MAKE) clean -C ./utilities
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./utilities
	$(RM) $(NAME) push_swap

re: fclean all

.SILENT:
