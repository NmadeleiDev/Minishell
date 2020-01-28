NAME1 = echo
NAME2 = env
NAME3 = play
LIBFT = ../ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror -g
CFLAGS = -I.
DEPS = ../shell_header.h
OBJ = ./ft_echo.o ./ft_play.o ./env.o ../searching.o ../supports.o\
../ft_cd.o ../ft_setenv.o ../read_command.o ../enviroment.o

%.o: %.c $(DEPS)
	@gcc $(FLAGS) -c -o $@ $< $(CFLAGS)

%.o : $(DEPS)

all: $(OBJ)
	@gcc $(FLAGS) -o $(NAME1) $(filter-out ./ft_play.o ./env.o,$(OBJ)) $(CFLAGS) $(LIBFT)
	@gcc $(FLAGS) -o $(NAME2) $(filter-out ./ft_echo.o ./ft_play.o,$(OBJ)) $(CFLAGS) $(LIBFT)
	@gcc $(FLAGS) -o $(NAME3) $(filter-out ./ft_echo.o ./env.o,$(OBJ)) $(CFLAGS) $(LIBFT)

.PHONY: clean fclean re all

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@rm -f $(NAME3)

re: fclean all
