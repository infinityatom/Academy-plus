NAME 	= mylib.a
FLAGS 	= -Wall -Wextra -Werror

SRC =				\
	ft_atoi.c		\
	ft_ftoa.c		\
	ft_itoa.c		\
	ft_memchr.c		\
	ft_memcmp.c		\
	ft_memset.c		\
	ft_printf.c		\
	ft_putfloat.c	\
	ft_putnbr.c		\
	ft_putstr.c		\
	ft_strcpy.c		\
	ft_strdup.c		\
	ft_strlen.c		\
	ft_strncat.c	\
	ft_strnew.c		\
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
