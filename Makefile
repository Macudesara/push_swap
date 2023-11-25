# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 11:07:33 by mde-sara          #+#    #+#              #
#    Updated: 2023/11/15 11:25:47 by mde-sara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
CC =		gcc
FLAGS =		-Wall -Wextra -Werror
DEPFLAGS =	-MMD -MP

SOURCES = free_stack.c ini_stack.c main.c push.c reverserotate.c rotate.c sort_xnumbers.c stack_sorted.c swap.c utils.c

OBJECTS = $(SOURCES:.c=.o)

DEPS = $(SOURCES:.c=.d)

INCLUDE	= -I includes -I libft
LIB_EXE	= libft/libft.a

all: make_libft $(NAME)

make_libft: ## Esta regla invoca make en el directorio libft para construir la biblioteca libft.a.
		@$(MAKE) -C ./libft

$(NAME): $(OBJECTS) Makefile
	$(CC) $(FLAGS) $(LIB_EXE) $(OBJECTS) -o $(NAME)

%.o: %.c
		@mkdir -p $(dir $@)
		$(CC) $(FLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJECTS) $(DEPS) $(NAME)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f push_swap.a
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
