NAME = libmylib.a

FLAGS = -Wall -Wextra -Werror

SRC =					\
	ft_memcpy.c			\
	ft_realloc.c		\
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

re:	fclean all
