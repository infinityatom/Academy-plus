#include "vector3.h"

t_vector3	*vector3_scalar_add(t_vector3 *dest, const t_vector3 *v, const t_v3float s)
{
	dest->x = v->x + s;
	dest->y = v->y + s;
	dest->z = v->z + s;
	return (dest);
}

t_vector3	*vector3_scalar_sub(t_vector3 *dest, const t_vector3 *v, const t_v3float s)
{
	dest->x = v->x - s;
	dest->y = v->y - s;
	dest->z = v->z - s;
	return (dest);
}

t_v3float	vector3_dot(const t_vector3 *a, const t_vector3 *b)
{
	return (a->x*b->x + a->y*b->y + a->z*b->z);
}

t_vector3	*vector3_cross(t_vector3 *dest, const t_vector3 *a, const t_vector3 *b)
{
	dest->x = a->y*b->z - a->z*b->y;
	dest->y = a->z*b->x - a->x*b->z;
	dest->z = a->x*b->y - a->y*b->x;
	return (dest);
}
