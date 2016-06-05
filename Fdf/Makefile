NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./Libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h

SRC =	main.c			\
		ft_read_file.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C Libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L Libft/ -lft -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	make -C Libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C Libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
