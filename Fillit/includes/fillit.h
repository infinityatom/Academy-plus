/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 12:01:16 by rbodnare          #+#    #+#             */
/*   Updated: 2015/12/19 12:01:19 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define SIZE ((26 * 5 * 4) + 25)
# define SIZE_PIECES (22 * 4 * 4)
# define PIECES "pieces.txt"

# define FIND 0
# define FOUND 1
# define DID_FOUND 2

# define TO_FIND 1

typedef struct	t_coord
{
	int		x;
	int		y;
}				s_coord;

typedef struct	t_fillit
{
	char	***elem;
	char	*str;
	int		min;
	int		len;
}				s_fillit;

/*
** Utility functions
*/

void	print_square(char **square, int size);
int		set_find(int action, int value);
int		min_box_size(int len);
int		prepare(char ***elem, int len, int min);

/*
** Swap functions
*/

void	swap_2d_ext(char **a, char **b);
void	swap_2d(char **a, char **b);
void 	swap(char *a, char *b);

/*
** Functions for memory allocation
*/

void	free_two_d(char **data, char x);
char	**alloc_two_d(char x, char y);
void	free_three_d(char ***data, char x, char y);
char	***alloc_three_d(char x, char y, char z);
char	**alloc_matrix(char **matrix, int box);

/*
** Functions for validating
*/

int		compare_tetrimino(char *buf, char **piece, int n);
char	**check_type_tetrimino(char *buf, int i, char ***pieces);
int		validate_boxes(char *buf);

/*
** Functions for reading
*/

char	***extract_pieces(int i, int x, int y, int z);
char	***extract_tetriminos(char *buf, int boxes, int *len);
char	***read_the_tetriminos(char *file, int *len);

/*
** Functions to fill it
*/

void	delete_last(s_fillit *obj, char **matrix, int l);
void	placeit(s_fillit *obj, s_coord coord, char **matrix, int l);
int		can_be_placed(char **square, s_fillit *obj, s_coord coord, int l);
int		place(s_fillit *obj, char **matrix, int l);
void	fillit(s_fillit *obj, char **matrix, int l);

#endif
