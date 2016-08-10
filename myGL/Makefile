NAME = myGL.a
FLAGS = -Wall -Wextra -Werror

#other libraries
DIR		= myLib
LIB		= myLib/mylib.a

SRC =					\
	color_creations.c	\
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

cleantest: fclean all
		@for dir in $(DIR); do (make -C ../$$dir fclean); done
		@for dir in $(DIR); do (make -C ../$$dir all); done
		@gcc -I. -o test test.c $(NAME) $(LIB)
		@for dir in $(DIR); do (make -C ../$$dir clean); done
		@make clean
		@./test
		@rm test

test: re
		@gcc -I. -o test test.c $(NAME) $(LIB)
		@./test
		@rm test

cleanall: fclean
		@make -C $(DIR) fclean
