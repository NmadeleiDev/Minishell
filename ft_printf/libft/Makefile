# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 13:56:32 by nmadelei          #+#    #+#              #
#    Updated: 2019/11/26 11:28:02 by nmadelei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re

NAME = libft.a

SOURCES = ./get_next_line.c ./ft_itoa.c ./ft_isxdigit.c ./ft_putarr.c ./ft_memchr.c \
./ft_putendl_fd.c ./ft_strcpy.c ./ft_strmap.c ./ft_strsplit.c \
./ft_memcmp.c ./ft_putnbr.c ./ft_strdel.c ./ft_strmapi.c ./ft_strstr.c ./ft_atoi.c \
./ft_lstdel.c ./ft_memcpy.c ./ft_putnbr_fd.c ./ft_strdup.c ./ft_strncat.c ./ft_strsub.c \
./ft_bzero.c ./ft_lstdelone.c ./ft_memdel.c ./ft_putstr.c ./ft_strequ.c \
./ft_strncmp.c ./ft_strtrim.c ./ft_isalnum.c ./ft_lstiter.c ./ft_memmove.c \
./ft_putstr_fd.c ./ft_striter.c ./ft_strncpy.c ./ft_tolower.c ./ft_isalpha.c \
./ft_lstmap.c ./ft_memset.c ./ft_strcat.c ./ft_striteri.c ./ft_strnequ.c \
./ft_toupper.c ./ft_isascii.c ./ft_lstnew.c ./ft_putchar.c ./ft_strchr.c \
./ft_strjoin.c ./ft_strnew.c ./ft_isdigit.c ./ft_memalloc.c ./ft_putchar_fd.c \
./ft_strclr.c ./ft_strlcat.c ./ft_strnstr.c ./ft_isprint.c ./ft_memccpy.c \
./ft_putendl.c ./ft_strcmp.c ./ft_strlen.c ./ft_strrchr.c ./ft_get_node.c \
./ft_realloc.c ./ft_add_llast.c ./ft_strclen.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	gcc -c -Wall -Wextra -Werror $(SOURCES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
