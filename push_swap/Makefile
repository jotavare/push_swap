# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotavare <jotavare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 07:36:40 by jotavare          #+#    #+#              #
#    Updated: 2023/03/04 11:28:08 by jotavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
LIBFTPRINTF = ./source/libftprintf.a

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1m

# PUSH_SWAP
NAME = push_swap.a
SRCS = 	push_swap.c\
		utilities/swap.c\
		utilities/push.c\
		utilities/rotate.c\
		utilities/reverse.c\
		utilities/sort_small.c\
		utilities/sort_radix.c\
		utilities/validation.c\
		utilities/utilities.c
		
OBJS = $(SRCS:%.c=%.o)

# MAKE
all: $(NAME)

$(LIBFTPRINTF):
	$(MAKE) -C ./source

$(NAME): $(OBJS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTPRINTF) -o push_swap
	@echo "$(GREEN) [All files compiled!] $(BOLD)"
	@echo "$(GREEN) [./push_swap 1 2 3 4 5] $(BOLD)"

clean:
	$(MAKE) clean -C ./source
	$(RM) $(OBJS)
	@echo "$(RED) [Object files deleted!] $(BOLD)"

fclean: clean
	$(MAKE) fclean -C ./source
	$(RM) $(NAME) push_swap
	@echo "$(RED) [All files cleaned!] $(BOLD)"

re: fclean all

.SILENT:
