# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 11:28:36 by mde-sara          #+#    #+#              #
#    Updated: 2023/11/15 11:44:53 by mde-sara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
CC 		= gcc
FLAGS	= -Wall -Wextra -Werror
AR		= ar rc
RN 		= ranlib

#ar: se utiliza para crear y administrar archivos estáticos (.a)
#r: Esta opción indica a ar que se debe reemplazar cualquier archivo existente en el archivo estático si ya existe un archivo con el mismo nombre. Si no existe un archivo con el mismo nombre, se creará uno nuevo.
#c: Es similar a la opción r, pero no emite una advertencia si el archivo no existe.
#s: Esta opción agrega información de índice a la biblioteca estática. Esta información de índice se utiliza para acelerar la búsqueda de símbolos durante la vinculación.

SOURCES = ft_strlen.c ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_atoi.c ft_strdup.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c

OBJECTS = $(SOURCES:.c=.o)

DEPS = $(SOURCES:.c=.d)

all: $(NAME)

$(NAME): $(OBJECTS) Makefile
	$(AR) $(NAME) $(OBJECTS)
	$(RN) $(NAME)

##-MMD: le indica al compilador que genere un archivo de dependencia (.d) para cada archivo fuente (.c).
##-MP: le indica al compilador que genere reglas de objetivos phony para las dependencias*/

%.o: %.c
	$(CC) $(FLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJECTS) $(DEPS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

#Las reglas phony son reglas que no corresponden a archivos reales, sino a tareas que deben ejecutarse

.PHONY: all clean fclean re
