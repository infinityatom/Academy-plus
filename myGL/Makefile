NAME = myGL.a

FLAGS = -Wall -Wextra -Werror

SRC =					\
	v3_operations_1.c	\
	v3_operations_2.c	\
	v3_combinations.c	\
	v3_u_operations.c	\
	v3_creations.c

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
