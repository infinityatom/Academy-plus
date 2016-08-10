NAME = fdf.a
FLAGS = -Wall -Wextra -Werror

FILE = 42.fdf
FILE_PATH = test_maps/

#other libraries
DIR	=					\
	myGL				\
	myLib

LIB	=					\
	myGL/myGL.a			\
	myLib/mylib.a

SRC =					\
	read_file.c

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
		@gcc -I. -o fdf main.c $(NAME) $(LIB)
		@for dir in $(DIR); do (make -C ../$$dir clean); done
		@make clean
		@./fdf $(FILE_PATH)$(FILE)
		@rm fdf

test: re
		@gcc -I. -o fdf main.c $(NAME) $(LIB)
		@make clean
		@./fdf $(FILE_PATH)$(FILE)
		@rm fdf

cleanall: fclean
		@for dir in $(DIR); do (make -C ../$$dir fclean); done
