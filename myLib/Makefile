NAME 	= mylib.a
FLAGS 	= -Wall -Wextra -Werror

SRC =				\
	ft_atoi.c		\
	ft_ftoa.c		\
	ft_itoa.c		\
	ft_printf.c		\
	ft_putfloat.c	\
	ft_putnbr.c		\
	ft_putstr.c		\
	ft_strlen.c		\
	get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		@gcc -c $(FLAGS) $(SRC)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@rm -f $(OBJ)

fclean:	clean
		@rm -f $(NAME)

test:
		@make fclean
		@make all
		@gcc -I. -o test test.c $(NAME)
		@make clean
		@./test
		@rm test

re:	fclean all
