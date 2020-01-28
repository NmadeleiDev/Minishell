NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -g
CFLAGS = -I.
DEPS = ./includes/ft_printf.h ./includes/put_digits.h ./libft/libft.h
OBJ = ./sources/ft_printf.o ./sources/puts_digits.o ./sources/puts_csp.o\
 ./sources/make_life_easier.o ./sources/put_float.o ./sources/read_format.o \
 ./sources/print_order.o ./put_digits/put_ascii_nums.o ./sources/tools_to_read_form.o\
./put_digits/get_base_num.o ./put_digits/put_int.o ./put_digits/put_llong.o\
./put_digits/put_long.o ./put_digits/put_schar.o ./put_digits/put_short.o\
./put_digits/put_unchar.o ./put_digits/put_unint.o ./put_digits/put_unllong.o\
./put_digits/put_unlong.o ./put_digits/put_unshort.o ./put_digits/get_unllong_to_str.o\
./put_floats/put_double.o ./put_floats/put_long_double.o ./put_floats/calculations.o ./put_floats/formate_float.o \
./put_floats/increase_str_num.o ./put_digits/put_intmax.o\
./put_digits/put_uintmax.o ./put_digits/put_size_t_num.o ./put_digits/get_base_convs.o\
./libft/get_next_line.o ./libft/ft_itoa.o ./libft/ft_isxdigit.o ./libft/ft_putarr.o ./libft/ft_memchr.o \
./libft/ft_putendl_fd.o ./libft/ft_strcpy.o ./libft/ft_strmap.o ./libft/ft_strsplit.o\
./libft/ft_memcmp.o ./libft/ft_putnbr.o ./libft/ft_strdel.o ./libft/ft_strmapi.o ./libft/ft_strstr.o ./libft/ft_atoi.o \
./libft/ft_lstdel.o ./libft/ft_memcpy.o ./libft/ft_putnbr_fd.o ./libft/ft_strdup.o ./libft/ft_strncat.o ./libft/ft_strsub.o \
./libft/ft_bzero.o ./libft/ft_lstdelone.o ./libft/ft_memdel.o ./libft/ft_putstr.o ./libft/ft_strequ.o \
./libft/ft_strncmp.o ./libft/ft_strtrim.o ./libft/ft_isalnum.o ./libft/ft_lstiter.o ./libft/ft_memmove.o \
./libft/ft_putstr_fd.o ./libft/ft_striter.o ./libft/ft_strncpy.o ./libft/ft_tolower.o ./libft/ft_isalpha.o \
./libft/ft_lstmap.o ./libft/ft_memset.o ./libft/ft_strcat.o ./libft/ft_striteri.o ./libft/ft_strnequ.o \
./libft/ft_toupper.o ./libft/ft_isascii.o ./libft/ft_lstnew.o ./libft/ft_putchar.o ./libft/ft_strchr.o \
./libft/ft_strjoin.o ./libft/ft_strnew.o ./libft/ft_isdigit.o ./libft/ft_memalloc.o ./libft/ft_putchar_fd.o \
./libft/ft_strclr.o ./libft/ft_strlcat.o ./libft/ft_strnstr.o ./libft/ft_isprint.o ./libft/ft_memccpy.o \
./libft/ft_putendl.o ./libft/ft_strcmp.o ./libft/ft_strlen.o ./libft/ft_strrchr.o ./libft/ft_get_node.o \
./libft/ft_realloc.o ./libft/ft_add_llast.o ./libft/ft_new_nulled_str.o ./libft/ft_strclen.o

%.o: %.c $(DEPS)
	@gcc $(FLAGS) -c -o $@ $< $(CFLAGS)

%.o : $(DEPS)

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

all: $(NAME)

.PHONY: clean fclean re all

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf libftprintf.a ./libft/libft.a

re: fclean all
