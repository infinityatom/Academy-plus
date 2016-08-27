
#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>

# define t_v3float float

# ifndef EPSILON
#  define EPSILON 0.001f
# endif

typedef struct	s_vector3 {
	t_v3float	x;
	t_v3float	y;
	t_v3float	z;
}				t_vector3;

/*
** Arithmetic operations
*/

t_vector3	*vector3_add(t_vector3 *dest, const t_vector3 *v1, const t_vector3 *v2);
t_vector3	*vector3_subtract(t_vector3 *dest, const t_vector3 *min, const t_vector3 *sub);
t_vector3	*vector3_multiply(t_vector3 *dest, const t_vector3 *v, const t_v3float n);
t_vector3	*vector3_divide(t_vector3 *dest, const t_vector3 *v, const t_v3float n);
t_vector3	*vector3_scalar_add(t_vector3 *dest, const t_vector3 *v, const t_v3float s);
t_vector3	*vector3_scalar_sub(t_vector3 *dest, const t_vector3 *v, const t_v3float s);
t_v3float	vector3_dot(const t_vector3 *a, const t_vector3 *b);
t_vector3	*vector3_cross(t_vector3 *dest, const t_vector3 *a, const t_vector3 *b);

/*
** Unit operations
*/

t_v3float	vector3_length(const t_vector3 *a);
t_vector3	*vector3_normalize(t_vector3 *a);
t_vector3	*vector3_invert(t_vector3 *dest, const t_vector3 *v);
void		vector3_print(const t_vector3 *v);

/*
** Creation
*/

t_vector3	*new_vector3(t_v3float x, t_v3float y, t_v3float z);
t_vector3	vector3_make_between(const t_vector3 *to, const t_vector3 *from);
void		vector3_copy(t_vector3 *dest, const t_vector3 *source);

/*
** Combination operations
*/

t_v3float	vector3_distance(const t_vector3 *a, const t_vector3 *b);
double		vector3_distancesq(t_vector3 *a, t_vector3 *b);
t_v3float	vector3_angle(const t_vector3 *a, const t_vector3 *b);
t_vector3	*vector3_reflect(t_vector3 *dest, const t_vector3 *inc, const t_vector3 *norm);

#endif
