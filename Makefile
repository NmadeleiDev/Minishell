NAME = minishell
LIBFT = ./ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror -g
CFLAGS = -I.
DEPS = ./shell_header.h
OBJ = ./main.o ./searching.o ./ft_cd.o ./ft_setenv.o\
./read_command.o ./enviroment.o ./supports.o ./ft_split_whitespaces.o

%.o: %.c $(DEPS)
	@gcc $(FLAGS) -c -o $@ $< $(CFLAGS)

%.o : $(DEPS)

$(NAME): $(OBJ)
	@make -C ./ft_printf
	@make -C ./bi
	@gcc $(FLAGS) -o $@ $(OBJ) $(CFLAGS) $(LIBFT)

all: $(NAME)

.PHONY: clean fclean re all

clean:
	@make clean -C ./ft_printf
	@make clean -C ./bi
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./bi
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: fclean all
