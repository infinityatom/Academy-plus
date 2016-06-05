
#ifndef VECTOR3_H
# define VECTOR3_H

# include <math.h>

# define v3float float

# ifndef EPSILON
#  define EPSILON 0.001f
# endif

typedef struct	s_vector3 {
	v3float		x;
	v3float		y;
	v3float		z;
}				vector3;

/*
** Arithmetic operations
*/

vector3	*vector3_add(vector3 *dest, const vector3 *v1, const vector3 *v2);
vector3	*vector3_subtract(vector3 *dest, const vector3 *min, const vector3 *sub);
vector3	*vector3_multiply(vector3 *dest, const vector3 *v, const v3float n);
vector3	*vector3_divide(vector3 *dest, const vector3 *v, const v3float n);
vector3	*vector3_scalar_add(vector3 *dest, const vector3 *v, const v3float s);
vector3	*vector3_scalar_sub(vector3 *dest, const vector3 *v, const v3float s);
v3float	vector3_dot(const vector3 *a, const vector3 *b);
vector3	*vector3_cross(vector3 *dest, const vector3 *a, const vector3 *b);

/*
** Unit operations
*/

v3float	vector3_length(const vector3 *a);
vector3	*vector3_normalize(vector3 *a);
vector3	*vector3_invert(vector3 *dest, const vector3 *v);
void	vector3_print(const vector3 *v);

/*
** Creation
*/

vector3	*vector3_copy(vector3 *dest, const vector3 *source);
vector3	*vector3_random(vector3 *v);
vector3	*vector3_make3f(vector3 *v, v3float x, v3float y, v3float z);
vector3	*vector3_make2v(vector3 *v, const vector3 *to, const vector3 *from);

/*
** Combination operations
*/

v3float vector3_distance(const vector3 *a, const vector3 *b);
double	vector3_distancesq(vector3 *a, vector3 *b);
v3float vector3_angle(const vector3 *a, const vector3 *b);
vector3	*vector3_reflect(vector3 *dest, const vector3 *inc, const vector3 *norm);

#endif
