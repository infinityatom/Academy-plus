NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC =				\
	ft_ftoa.c		\
	ft_itoa.c		\
	ft_memcpy.c		\
	ft_printf.c		\
	ft_putchar.c	\
	ft_putfloat.c	\
	ft_putnbr.c		\
	ft_putstr.c		\
	ft_putwchar.c	\
	ft_realloc.c	\
	ft_strlen.c

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

test: all
		@gcc -I. -o test test.c $(NAME)
		@./test

cleantest: test
	@make fclean
	@rm test

re:	fclean all
